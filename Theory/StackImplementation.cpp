#include<iostream>
using namespace std;
#define MAX 100 
class stack
{
	int top;
	int arr[MAX];
	public:
		stack()
		{
			top = -1;
		}
		void push(int num)
		{
			if(top>=MAX)
				cout<<"Overflow\n";
			else
			{
				top++;
				arr[top]=num;
			}
		}
		int pop()
		{
			
			if(top<0)
			{
				cout<<"Underflow\n";
				return 0;
			}
			else
			{
				int x=arr[top];
				top--;
				return x;
			}
		}
		bool isEmpty()
		{
			if(top<0)
				return 1;
			else
				return 0;
		}
		void display()
		{
			if(isEmpty())
			{
				cout<<"Empty Stack\n";
				return;
			}
			cout<<pop()<<"\t";
			display();
			cout<<endl;
		}
};
int main()
{
	stack s;
	int d;
	cout<<"Enter the elements in stack, to stop entering values, press -1\n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		s.push(n);
		cin>>n;
	}
	cout<<"The Stack is:\n";
	s.display();
	cout<<"To pop an element press 1\n";
	cin>>d;
	switch(d)
	{
		case 1:
		{
			cout<<"Element popped:\n";
			cout<<s.pop()<<endl;
			s.display();
			break;
		}
	}
	return 0;
}
