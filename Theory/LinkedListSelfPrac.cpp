#include<iostream>
using namespace std;
struct node
{
	int value;
	node *next;
};
class linked_list
{
	node *head,*tail;
	public:
		linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		void creatNode(int v)
		{
			node *t = new node;
			t -> value = v;
			t -> next = NULL;
			if(head == NULL)
			{
				head = t;
				tail = t;
			}
			else
			{
				tail -> next = t;
				tail = t;
			}
		}
		void display()
		{
			node *temp = new node;
			temp = head;
			while(temp != NULL)
			{
				cout<<temp->value<<"\t";
				temp = temp -> next;
			}
			cout<<endl;
		}
		void insert_start(int val)
		{
			node *temp = new node;
			temp -> value = val;
			temp -> next = head;
			head = temp;
		}
		void insert_end(int val)
		{
			node *temp = new node;
			temp -> value = val;
			temp -> next = NULL;
			tail -> next = temp;
		}
		void insert_pos(int pos,int val)
		{
			node *temp = new node;
			node *pre = new node;
			node *curr = new node;
			curr = head;
			for(int i = 0 ; i < pos ; i ++)
			{
				pre = curr;
				curr = curr -> next;
			}
			temp -> value = val;
			pre -> next = temp;
			temp -> next = curr;
		}
		void del_start()
		{
			node *temp = new node;
			temp = head;
			head = head->next;
			delete temp;
		}
		void del_end()
		{
			node *curr = new node;
			node *pre = new node;
			curr = head;
			while(curr->next != NULL)
			{
					pre = curr;
					curr = curr->next;
			}
			tail = pre;
			pre->next = NULL;
			delete curr;
		}
		void del_pos(int pos)
		{
			node *pre = new node;
			node *curr = new node;
			curr = head;
			for(int i = 0 ; i < pos ; i ++)
			{
				pre = curr;
				curr = curr->next;
			}
			pre->next = curr->next;
		}
};
int main()
{
	int n,a,b;
	cout<<"Enter how much elements you want in list?\n";
	cin>>n;
	cout<<"Enter elements\n";
	int val;
	linked_list L;
	for(int i = 0 ; i < n ; i ++)
	{
		cin>>val;
		L.creatNode(val);
	}
	L.display();
	cout<<"Enter element to insert at start\n";
	cin>>a;
	L.insert_start(a);
	L.display();
	cout<<"Enter element to insert at end\n";
	cin>>a;
	L.insert_end(a);
	L.display();
	int v,p;
	cout<<"Enter what value you want to insert and at what position?\n";
	cin>>v>>p;
	L.insert_pos(p,v);
	L.display();
	L.del_start();
	cout<<"After deleting element at start\n";
	L.display();
	cout<<"After deleting element at end\n";
	L.del_end();
	L.display();
	cout<<"Enter the position you want to delete\n";
	cin>>b;
	L.del_pos(b);
	L.display();
	return 0;
}
