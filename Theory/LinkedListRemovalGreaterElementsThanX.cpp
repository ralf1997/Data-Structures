#include<iostream>
using namespace std;
struct node
{
	int value;
	node *next;
};
class Linked
{
	node *head,*tail;
	public:
		Linked()
		{
			head = NULL;
			tail = NULL;
		}
		void createNode(int v)
		{
			node *temp = new node;
			temp->value = v;
			temp->next = NULL;
			if(head == NULL)
			{
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else
			{
				tail->next = temp;
				tail = temp;
				tail->next = NULL;
			}
		}
		void display()
		{
			node *temp = new node;
			temp = head;
			while(temp != NULL)
			{
				cout<<temp->value;
				temp = temp->next;
			}
		}
		void removeNode(int x)
		{
			
		}
};
int main()
{
	
	return 0;
}
