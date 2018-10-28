#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter elements in array, to stop entering press -1\n";
	int i = 0,a[10],n = 0;
	cin>>n;
	while(n != -1)
	{
		a[i] = n;
		i++;
		cin>>n;
	}
	
	for(int j = 0 ; j < i ; j ++)
	{
		if(j % 2 != 0)
		{
			a[j] =a[j]-( a[j] * 0.05);
		}
		else if(j % 2 == 0)
		{
			a[j] = a[j] - (a[j] * (0.1));
		}
	}
	cout<<"Array after deducing 10% from odd places and 5% from even places is:\n";
	for(int j = 0 ; j < i ; j ++)
	{
		cout<<a[j]<<"\t";
	}
	return 0;
}
