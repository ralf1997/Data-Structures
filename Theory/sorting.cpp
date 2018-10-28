#include<iostream>
using namespace std;
int main()
{
	int n,temp;
	cout<<"enter size of array\n";
	cin>>n;
	int a[ n ];
	cout<<"Enter elements of array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0 ; i < n - 1 ; i ++) {
		for(int j = 0 ; j < n - i - 1 ; j++) {
			if(a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;	
			}
		}
	} 
	cout<<"Array is\n";
	for(int i = 0 ; i < n ; i ++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}
