#include<iostream>
using namespace std;
#define MAX 20
int queue[MAX];
int front;
int rear;
bool isEmpty()
{
	if(front==-1 & rear==-1)
		return 1;
	else
		return 0;
}
void enqueue(int num)
{
	if(rear==MAX-1) //fully filled
		cout<<"Queue is full\n";
	else if(isEmpty()) //if it is empty
	{
		++rear;
		++front; //front is to be incremented inly at first time.
		queue[rear]=num;
	}
	else //if there are other elements
	{
		rear++;
		queue[rear]=num;
	}
}
void deque()
{
	if(isEmpty())
		cout<<"Empty\n";
	else if(rear==front)
	{
		rear=-1;
		front=-1;
	}
	else
		front++;
}
void display()
{
	cout<<"The queue is:\n";
	for(int i=front;i<=rear;i++)
	{
		cout<<queue[i]<<"\t";
	}
	cout<<endl;
}
int main()
{
	front=-1;
	rear=-1;
	int n;
	int c;
	cout<<"Press 1 to continue and -1 to exit\n";
	cin>>c;
	while(c!=-1)
	{
		cout<<"Enter 1 to insert elements in queue\n";
		cout<<"Enter 2 to delete an element\n";
		cin>>n;
		switch(n)
		{
			case 1:
				{
					int d;
					cout<<"Enter elements,to stop press -1\n";
					cin>>d;
					while(d!=-1)
					{
						enqueue(d);
						cin>>d;
					}
					break;
				}
			case 2:
				{
					deque();
					break;
				}
		}
		display();
		cout<<"If you would like to discontinue,press -1,otherwise press 1\n";
		cin>>c;
	}
}
