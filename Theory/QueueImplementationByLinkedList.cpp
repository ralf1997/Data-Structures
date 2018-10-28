#include<iostream>
using namespace std;
struct node
{
	int val;
	node *next;
};
class ListQueue
{
	node *front=new node;
	node *rear=new node;
	public:
		ListQueue()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue(int num)
		{
			node *temp=new node;
			temp->val=num;
			temp->next=NULL; //insertion is to be done at rear end, i.e. at end...
			if(front==NULL)
			{
				front=temp;
				rear=temp;
			}
			else
			{
				rear->next=temp;
				rear=temp;
			}
		}
		int dequeue()
		{
			node *ptr;
			int x;
			ptr=front;
			x=ptr->val;
			front=front->next;
			delete ptr;
			return x;
		}
		void display()
		{
			while(true)
			{
				if (front != NULL)
            		cout<<dequeue()<<endl;
        		else
            		break;
			}
		}
};
int main()
{
	ListQueue l;
	int choice=0,ele,d;
	cout<<"To proceed, press 1\n";
	cin>>choice;
	while(choice!=-1)
	{
		cout<<"To enter elements in queue, press 1,to delete press 2\n";
		cin>>d;
		switch(d)
		{
			case 1:
				{
					cout<<"Enter elements in queue, to stop entering, press -1\n";
					cin>>ele;
					while(ele!=-1)
					{
						l.enqueue(ele);
						cin>>ele;
					}
					break;
				}
			case 2:
				{
					cout<<"Element deleted is: "<<l.dequeue();
					break;
				}
		}
		cout<<"To discontinue, press -1 and to coninue press 1\n";
		cin>>choice;
	}
	l.display();
	return 0;
}
