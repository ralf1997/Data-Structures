#include<iostream>
using namespace std;
struct node
{
	int val;
	int priority;
	node *next;
};
class PriQueue
{
	node *front,*rear;
	public:
		PriQueue()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue(int item,int pri)
		{
			node *temp = new node;
			temp->val=item;
			temp->priority=pri;
			if(front == NULL || front->priority > pri)
			{
				temp->next = front;
				front = temp;
			}
			else
			{
				node *ptr;
				ptr = front;
				while(ptr->next != NULL)
				{
					if( ptr->next->priority > pri )
						break;
					else
						ptr = ptr->next;
				}
				if(pri>ptr->priority)
				{
					temp->next = ptr->next;
					ptr->next = temp;
				
				}
				else
				{
					temp->next=NULL;
					ptr->next=temp;
				}
			}
		}
		void display()
		{
			node *dis = new node;
			dis = front;
			while(dis!=NULL)
			{
				cout<<"Value: "<<dis->val<<" Priority: "<<dis->priority<<endl;
				dis = dis->next;
			}
		}
};
int main()
{
	PriQueue p;
	int choice,what,val,pri;
	cout<<"Press -1 to discontinue and press 1 to continue\n";
	cin>>choice;
	while(choice!=-1)
	{
		cout<<"To insert elements in queue,press 1\n";
		cin>>what;
		switch(what)
			{
				case 1:
					{
						cout<<"Enter the value of element and its priority\n";
						cin>>val>>pri;
						p.enqueue(val,pri);
						break;
					}
			}
		cout<<"Press -1 to discontinue and press 1 to continue\n";
		cin>>choice;
	}
	p.display();
	return 0;
}
