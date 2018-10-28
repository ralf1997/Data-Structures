#include<iostream>
using namespace std;
#define max_stk 5
int stack[max_stk];
int top = -1;
void push(int t)
{
		
	if(top == max_stk)
	{
		cout<<"Overflow\n";
		return;
	}
	else
	{
		top++;
		stack[top] = t;
	}
}
void pop()
{
	if(top == -1)
	{
		cout<<"Underflow";
		return;
	}
	else
	{
		top--;
	}
	
}	
int main()
{
	int n,size;
	cout<<"Enter how much elements you want to enter\n";
	cin>>size;
	cout<<"Enter element to push in the stack\n";
	for(int i = 0 ; i < size ; i ++) 
	{
		cin>>n;
		push(n);
	}
	for(int i = 0 ; i < size ; i++)
	{
		cout<<stack[i]<<"\t";
	}
	pop();
}
