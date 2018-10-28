#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class GRAPH
{
	int v,e;
	node *start[4];
	node *temp;
	node *ptr;
	public:
		GRAPH(int ver,int edg)
		{
			v = ver;
			e = edg;
			for(int i=0;i<v;i++)
			{
				start[i] = NULL;
			}
		}
		void create_graph()
		{
			int val;
			
			for(int i=0;i<v;i++)
			{
				cout<<"Enter the nodes to be connected for "<<i<<" node and press -1 to stop\n";
				cin>>val;
					
				while(val != -1)
				{
					temp = new node;
					temp->data = val;
					temp->next = NULL;
					if(start[i] == NULL)
					{
						start[i] = temp;
					}
					else
					{
						
						ptr=start[i];
						while(ptr->next!= NULL)
							ptr = ptr->next;
						ptr->next = temp;
					}
					cout<<"\nEnter next ";
					
					cin>>val;
				}
			}
		}
		void display()
		{
			node *ptr;
			cout<<"The adjancey list is\n";
			for(int i=0;i<v;i++)
			{
				ptr = start[i];
				while(ptr!=NULL)
				{
					cout<<ptr->data<<"\t";
					ptr = ptr->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	int ver,edg;
	cout<<"Enter number of vertices and edges\n";
	cin>>ver>>edg;
	GRAPH g(ver,edg);
	g.create_graph();
	g.display();
}
