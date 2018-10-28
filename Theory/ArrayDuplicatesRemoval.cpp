#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter size of array\n";
	cin>>n;
	cout<<"Enter elements of array\n";
	int a[n];
	for(int i = 0 ; i < n ; i ++)
	{
		cin>>a[i];
	}
	cout<<"The array is:\n";
	for(int i = 0 ; i < n ; i ++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	int count = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int k = i+1 ; k < n ; k ++)
		{
			if(a[i] == a[k])
			{
				for(int j = k ; j < n ; j ++)
				{
					a[j] = a[j + 1];
				}
				count++;
			}
		}
	}
	cout<<"Array after removal of duplicates is:\n";
	for(int i = 0 ; i < n - count + 1 ; i ++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}
