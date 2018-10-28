#include<iostream>
using namespace std;
int main()
{
	int n,val,pos;
	cout<<"Enter size of array\n";
	cin>>n;
	int arr[30];
	cout<<"Enter elements\n";
	for(int i = 0 ; i < n ; i ++)
	{
		cin>>arr[i];
	}
	cout<<"The array is:\n";
	for(int i = 0 ; i < n ; i ++)
	{
		cout<<arr[i]<<"\t";
	}
	//insertion
	cout<<"\nEnter what value you want to insert at what position?\n";
	cin>>val>>pos;
	for(int i = n ; i > pos ; i --)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = val;
	cout<<"Array after insertion is\n";
	for(int i = 0 ; i < n + 1 ; i ++)
	{
		cout<<arr[i]<<"\t";
	}
	//deletion
	int p,count = 0,del;
	cout<<"\nIf you want to delete an element by giving its value press 1"; 
	cout<<" and if you want to delete an element by giving its position then press 2\n";
	cin>>p;
	switch(p)
	{
		case 1:
			cout<<"Enter value\n";
			cin>>del;
			for(int i = 0 ; i < n + 1 ; i ++)
			{
				if(arr[i] == del)
				{
					for(int j = i ; j < n ; j ++)
					{
						arr[j] = arr[j + 1];
					}
					count++;
					break;
				}
			}
			if(count == 0)
			{
				cout<<"Enter a valid element to be deleted\n";
			}
			else
			{
				cout<<"Array after deleteion is \n";
				for(int i = 0 ; i < n ; i ++)
				{
					cout<<arr[i]<<"\t";
				}
				cout<<endl;
			}
			break;
		case 2:
			cout<<"Enter position\n";
			cin>>del;
			for(int i = 0 ; i < n + 1 ; i ++)
			{
				if(i == del)
				{
					for(int j = i ; j < n ; j ++)
					{
						arr[j] = arr[j + 1];
					}
					break;
				}
			}
			for(int i = 0 ; i < n ; i ++)
			{
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
			break;
		default:
			cout<<"Enter a valid coice\n";
			break;
	}
	//searching
	int ser,c = 0;
	cout<<"Enter what element you want to search\n";
	cin>>ser;
	for(int i = 0 ; i < n ; i ++)
	{
		if(arr[i] == ser)
		{
			c = i;
			break;
		}
	}
	if(c == 0)
	{
		cout<<"Element not found\n";
	}
	else
	{
		cout<<"Element found at "<<c<<endl;
	}
	//display
	cout<<"The array is now:\n";
	for(int i = 0 ; i < n ; i ++)
	{
		cout<<arr[i]<<"\t";
	}
	return 0;
}
