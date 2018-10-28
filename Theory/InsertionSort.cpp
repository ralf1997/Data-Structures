#include<iostream>
using namespace std;
void insSort(int *arr,int n)
{
	int j,temp;
	for(int i = 1 ; i < n ; i ++)
	{
		j = i - 1;
		while(j>=0 && arr[i]<arr[j])
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			j--;
			i--;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements in array\n";
	cin>>n;
	int arr[n];
	cout<<"Enter elements\n";
	for(int i = 0 ; i < n ; i ++)
		cin>>arr[i];
	insSort(arr,n);
}
