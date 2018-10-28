#include<iostream>
using namespace std;
class GRAPH
{
	int v,e;
	int **AM;
	public:
		GRAPH()
		{
			cout<<"Enter number of vertices and edges\n";
			cin>>v>>e;
			AM = new int *[v];	
			for(int i=0;i<v;i++)
			{
				
				AM[i] = new int[v];
			}
			
					for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
					AM[i][j] = 0;
				 
			}
		}
		void create_graph()
		{
			int v1,v2;
			for(int i=0;i<e;i++)
			{
				cout<<"Enter the 2 vertices in which you want to make connection\n";
				cin>>v1>>v2;
				AM[v1][v2] = 1;
			}
		}
		void display()
		{
			cout<<"The adjancy matrix is\n";
			for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
					cout<<AM[i][j]<<"\t";
				cout<<endl;
			}
			cout<<endl;
		}
};
int main()
{
	GRAPH g;
	g.create_graph();
	g.display();
	return 0;
}
