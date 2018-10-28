#include<iostream>
using namespace std;
int i = 0 , j = 0 , k = 0 ;
void merging( int arr[] , int p , int q , int r )
{
	int n1 = q - p + 1 ;
	int n2 = r - q ;
	int L[n1];
	int R[n2];
	int x=p;
	for( i = 0 ; i < n1 ;i ++ )
	{
		L[ i ] = arr[ x ] ;
		x ++ ;
	}
	for( j = 0 ; j < n2 ; j ++ )
	{
		R[ j ] = arr[ q + 1 ] ;
		q ++ ;
	}
	i = 0 ;
	j = 0 ;
	k = p ;
	while(i<n1 &&j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int p,int r)
{
	if(p<r)
	{
		int q = (p + r)/2 ;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merging(arr,p,q,r);
	}
}
void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter size\n";
	cin>>n;
	int arr[n];
	cout<<"Enter elements\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Array is\n";
	print(arr,n);
	mergeSort(arr,0,n-1);
	cout<<"Sorted array is\n";
	print(arr,n);
	return 0;
}
