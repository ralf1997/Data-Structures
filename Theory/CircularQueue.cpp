#include<iostream>
#define size 10
using namespace std;
class cir_queue
{
	int arr[20],front,rear;
	public:
		cir_queue()
		{
			front=-1;
			rear=-1;
		}
		void enqueue(int num)
		{
			if((front==0 && rear==size-1) || (front==rear+1) )
				cout<<"Overflow";
			else if(front==-1 && rear==-1)
			{
				front=0;
				rear=0;
				arr[rear]=num;
			}
			else
			{
				if(rear==size-1)
					rear=0;
				else
					rear++;
				arr[rear]=num;
			}
		}
		int deque()
		{
			int temp=-1;
			if(front==-1 && rear==-1) //no element
			{
				return temp;
			}
			else if(front==rear) //only one element
			{
				temp=arr[rear];
				front=-1;
				rear=-1;
				return temp;
			}
			else
			{
				if(front==size-1)
				{
					temp=arr[front];
					front=0;
				}
				else
				{
					temp=arr[front];
					front++;
				}
				return temp;
			}
		}
		void display()
		{
			int front_pos = front, rear_pos = rear;
            if (front == -1)
            {
                cout<<"Queue is empty\n";
                return;
            }
            cout<<"Queue elements :\n";
            if (front_pos <= rear_pos)
            {
                while (front_pos <= rear_pos)
                {
                    cout<<arr[front_pos]<<"  ";
                    front_pos++;
                }
            }
            else
            {
                while (front_pos <= size - 1)
                {
                    cout<<arr[front_pos]<<"  ";
                    front_pos++;
                }
                front_pos = 0;
                while (front_pos <= rear_pos)
                {
                    cout<<arr[front_pos]<<"  ";
                    front_pos++;
                }
            }
			cout<<endl;
		}
};
int main()
{
	cir_queue obj;
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
						obj.enqueue(d);
						cin>>d;
					}
					break;
				}
			case 2:
				{
					obj.deque();
					break;
				}
		}
		obj.display();
		cout<<"If you would like to discontinue,press -1,otherwise press 1\n";
		cin>>c;
	}
	return 0;
}
