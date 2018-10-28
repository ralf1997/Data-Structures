#include<iostream>
using namespace std;
struct BST
{
	int info;
	BST *left;
	BST *right;
}*root=NULL;
void create_BST()
{
	int num;
	BST *check = new BST;
	cout<<"Enter values in Tree,to stop press -1\n";
	cin>>num;
	while(num!=-1)
	{
		BST *new_node = new BST;
		new_node->info = num;
		new_node->left = NULL;
		new_node->right = NULL;
		if(root == NULL)
			root = new_node;
		else
		{
			check = root;
			while(1)
			{
				if(check->info<num)
				{
					if(check->right==NULL)
					{
						check->right = new_node;
						cout<<"Parent is "<<check->info<<endl;
						break;
					}
					else
						check = check->right;
				}
				else
				{
					if(check->left == NULL)
					{
						check->left = new_node;
						cout<<"Parent is "<<check->info<<endl;
						break;
					}
					else
						check = check->left;
				}
			}
		}
		cin>>num;
	}
}
void inOrder(BST *curr)
{
	if(root==NULL)
		return;
	if(curr!=NULL)
	{
		inOrder(curr->left);
		cout<<curr->info<<"\t";
		inOrder(curr->right);
	}
	cout<<endl;
}
void find_prod(BST *ptr,int *p)
{
	if(!ptr)
		return;
	if((ptr->left!=NULL && ptr->right==NULL) || (ptr->left==NULL && ptr->right!=NULL))
	{
		*p *= ptr->info;
	}
	find_prod(ptr->left,p);
	find_prod(ptr->right,p);
}
int main()
{
	int prod=1;
	create_BST();
	cout<<"In order traversal is\n";
	inOrder(root);
	BST *ptr = root;
	find_prod(ptr,&prod);
	cout<<"Product of nodes having single child is "<<prod;
	return 0;
}
