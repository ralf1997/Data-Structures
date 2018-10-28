#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter size of array\n";
	cin>>n;
	int a[ 30 ];
	cout<<"Enter elements of array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Array is\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	//searching
	int s;
	cout<<"\nEnter element to be searched\n";
	cin>>s;
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(s == a[i]){
			f = i;
			break;
		}
	}
	if(f != 0) {
		cout<<"Element "<<s<<" found at position "<<f<<endl;
	}
	else
	{
		cout<<"Element not found\n";
	}
	//insertion
	int ins,pos;
	cout<<"Enter what integer element do you want to insert and at what position\n";
	cin>>ins;
	cin>>pos;
	for(int  i = n ; i > pos ; i --)
	{
		a[i] = a[i - 1];
	}
	a[pos] = ins;
	cout<<"Element inserted successfully\n";
	cout<<"Array after insertion is:\n";
	for(int i = 0 ; i < n + 1 ; i ++) {
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	//deletion
	int del,count=0;
	cout<<"enter what array element you want to delete.\n";
	cin>>del;
	for( int i = 0 ; i < n + 1 ; i ++) {
		if(a[i] == del)
		{
			for(int j = i ; j < n ; j ++)
			{
				a[j] = a[j + 1];
			}
			count++;
			break;
		}
	}
	if(count == 0)
	{
		cout<<"Element not found\n";
	}
	else
	{
		cout<<"The array after deletion is\n";
		for(int i = 0 ; i < n ; i ++) {
			cout<<a[i]<<"\t";
		}
	}
	cout<<endl;
	//updation
	int up,val;
	cout<<"Enter element to be updated and its new value\n";
	cin>>up>>val;
	for(int i=0;i<n;i++)
	{
		if(a[i] == up) {
			a[i] = val;
			break;
		}
	}
	cout<<"Array after updation is\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	//sorting
	int temp;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = i + 1 ; j < n ; j ++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout<<"Sorted array is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}
