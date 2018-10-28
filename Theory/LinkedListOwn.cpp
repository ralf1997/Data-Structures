#include<iostream>
using namespace std;
struct node
{
	int value;
	node *next;
};
class list
{
	node *head,*tail,*ptr;
	public:
		list()
		{
			head = NULL;
			tail = NULL;
			ptr = NULL;
		}
		void createNode(int x)
		{
			node *temp = new node;
			temp->value = x;
			temp->next = NULL;
			if(head == NULL)
			{
				head = temp;
				tail = temp;
				temp = NULL; //freeing memory for optimization
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}
		void display()
		{
			node *temp = new node;
			temp = head;
			cout<<"The list is:\n";
			while(temp != NULL)
			{
				cout<<temp->value<<"\t";
				temp = temp->next;
			}
			cout<<"\n";
		}
		void insert_beg(int num)
		{
			node *temp = new node;
			temp->value = num;
			temp->next = head;
			head = temp;
		}
		void insert_end(int num)
		{
			node *temp = new node;
			temp->value = num;
			temp->next = NULL; //keeping the address NULL as it is inserted in the end
			tail->next = temp; //giving it the new node's address
			tail = temp; //keeping last node saved for later use again
		}
		void insert_after(int num,int given)
		{
			ptr = head;
			while(ptr->value != given)
			{
				ptr = ptr->next;
			}
			node *temp = new node;
			temp->value = num;
			temp->next = ptr->next;
			ptr->next = temp;
		}
		void insert_before(int num,int given)
		{
			node *temp = new node;
			node *prev = new node;
			prev = NULL;
			ptr = head;
			while(ptr->value != given)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			if(prev == NULL)
			{
				insert_beg(num);
			}
			else
			{
				temp->value = num;
				temp->next = prev->next;
				prev->next = temp;
			}
		}
		void insert_sort(int num)
		{
			node *pre = new node;
			ptr = head;
			pre = NULL;
			while(ptr!=NULL && ptr->value<num) 
			{
		//keep ptr->value<num as second condition because at last ptr will be null and it'll be checking if NULL->value<num?
				pre = ptr;
				ptr = ptr->next;
			}
			if(pre == NULL)
			{
				insert_beg(num);
			}
			else if(ptr == NULL)
			{
				insert_end(num);
			}
			else
			{
				insert_after(num,pre->value);
			}
		}
		void del_beg()
		{
			ptr = head;
			head = ptr->next;
			ptr->next = NULL; //to free the memory, even if you dont write it, code will work fine, its just for optimization.
		}
		void del_end()
		{
			node *copy = new node;
			ptr = head;
			while(ptr->next != NULL)
			{
				copy = ptr;
				ptr = ptr->next;
			}
			copy->next = NULL;
			tail = copy;
			//delete ptr;
		}
		void del_ele(int d) //doubt
		{
			node *pre = new node;
			pre = NULL;
			ptr = head;
			while(ptr != NULL)
			{
				if(ptr->value == d)
					break;
				pre = ptr;
				ptr = ptr->next;
			}
			if(pre == NULL)
			{
				del_beg();
			}
			else if(ptr == NULL)
			{
				cout<<"Element not found\n";
			}
			else
			{
				pre->next = ptr->next;
				ptr->next = NULL;
			}
		}
		void sortList()
		{
			int a;
			node *i = new node;
			node *j = new node;
			i = head;
			j = i->next;
			while(i != NULL)
			{
				while(j != NULL)
				{
					if(i->value > j->value)
					{
						a = i->value;
						i->value = j->value;
						j->value = a;
					}
					j = j->next;
				}
				i = i->next;
				j = i;
			}
		}
};
int main()
{
	int n = 0 , v = 0 , g = 0;
	list L;
	cout<<"Enter the values of nodes\n";
	cout<<"To stop entering values, press -1\n";
	cin>>v;
	while(v != -1)
	{
		L.createNode(v);
		cin>>v;
	}
	L.display();
	cout<<"To insert an element at the beginning of a list, press 1\n";
	cout<<"To insert an element at the end of the list press 2\n";
	cout<<"To insert an element after an existing element press 3\n";
	cout<<"To insert an element before an existing element press 4\n";
	cout<<"To insert an element and getting the result sorted finally press 5\n";
	cout<<"To delete an element from beginning press 6\n";
	cout<<"To delete an element from end press 7\n";
	cout<<"To specify an element for deletion press 8\n";
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Enter what element you want to insert at the beginning?\n";
			cin>>v;
			L.insert_beg(v);
			L.display();
			break;
		case 2:
			cout<<"Enter element to insert in the end?\n";
			cin>>v;
			L.insert_end(v);
			L.display();
			break;
		case 3:
			cout<<"Enter value of element you want to insert and value of element after which you want to insert it.\n";
			cin>>v;
			cin>>g;
			L.insert_after(v,g);
			L.display();
			break;
		case 4:
			cout<<"Enter value of element you want to insert and value of element before which you want to insert it.\n";
			cin>>v;
			cin>>g;
			L.insert_before(v,g);
			L.display();
			break;
		case 5:
			cout<<"Enter element to get a sorted list \n";
			cin>>v;
			L.insert_sort(v);
			L.display();
			break;
		case 6:
			L.del_beg();
			L.display();
			break;
		case 7:
			L.del_end();
			L.display();
			break;
		case 8:
			cout<<"Enter value of element you want to delete\n";
			cin>>v;
			L.del_ele(v);
			L.display();
			break;
			
	}
	cout<<"To get the sorted list, press 1\n";
	cin>>n;
	switch(n)
	{
		case 1:
			L.sortList();
			break;
	}
	L.display();
	return 0;
}
