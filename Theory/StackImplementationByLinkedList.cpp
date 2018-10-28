#include<iostream>
using namespace std;
struct node
{
	int val;
	node *next;
};
class ListStack
{
	node *top;
	public:
		Liststack()
		{
			top=NULL;
		}
		void push(int num)
		{
			node *temp=new node;
			temp->val=num;
			temp->next=NULL;
			if(top!=NULL)
			{
				temp->next=top;
			}
			top=temp;
		}
		int pop()
		{
			node *ptr=new node;
			ptr=top;
			int x=ptr->val;
			top=ptr->next;
			ptr->next=NULL;
			return x;
		}
		void display()
		{
			node *str=new node;
			str=top;
			if(str==NULL)
			{
				return;
			}
			cout<<pop()<<"\t";
			display();
		}
};
int main()
{
	ListStack l;
	cout<<"To continue press 1,to stop , press -1\n";
	int con,v;
	cin>>con;
	while(con!=-1)
	{
		cout<<"Enter elements in stack,to stop press -1\n";
		int num;
		cin>>num;
		while(num!=-1)
		{
			l.push(num);
			cin>>num;
		}
		cout<<"To pop an element press 2\n";
		cin>>v;
		switch(v)
		{
			case 2:
				cout<<"Element popped, "<<l.pop()<<"\n";
				break;
			default:
				cout<<"Wrong choice\n";
				break;
		}
		cout<<"To continue press 1,to stop , press -1\n";
		cin>>con;
	}
	cout<<"Stack is:\n";
	l.display();
	return 0;
}
