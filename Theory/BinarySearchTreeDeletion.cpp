#include<iostream>
#include<queue>
#include<stack>
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
void del_leafNode(BST *parent,BST *check)
{
	if(parent->info < check->info)
		parent->right = NULL;
	else
		parent->left = NULL;
	delete check;
}
void del_singleChild(BST *par,BST *ptr)
{
	if(par->info >= ptr->info)
	{
		if(ptr->left!=NULL)
			par->left = ptr->left;
		else
			par->left = ptr->right;
	}
	else
	{
		if(ptr->left != NULL)
			par->right = ptr->left;
		else
			par->right = ptr->right;
	}
}
int del_twoChild(BST *test,BST *save)
{
	while(test->left != NULL)
	{
		save = test;
		test = test->left;
	}
	int x=test->info;
	if(test->left==NULL && test->right==NULL)
		del_leafNode(save,test);
	else
		del_singleChild(save,test);
	return x;
}
void search_del()
{
	BST *check;
	check = root;
	BST *parent = new BST;
	parent = NULL;
	int num;
	cout<<"Enter element you wanna delete\n";
	cin>>num;
	while(1)
	{
		if(check->info == num)
		{
			if(check->left == NULL && check->right == NULL)
			{
				del_leafNode(parent,check);
			}
			else if(check->left!=NULL && check->right!=NULL) //for a node with 2 children
			{
				parent = check;
				int value=del_twoChild(check->right,parent);
				check->info=value;
			}
			else if(check->left!=NULL || check->right!=NULL) //if both will be null it will go in first case.
			{
				del_singleChild(parent,check);
			}
			break;
		}
		else if(check->info<num && check->right != NULL)
		{
			parent = check;
			check = check->right;
		}
		else if(check->info>num && check->left != NULL)
		{
			parent = check;
			check = check->left;
		}
	}
}
void inOrder_withoutRec()
{
	BST *ptr;
	ptr = root;
	stack<BST *> stk;
	do
	{
		if(ptr)
		{
			stk.push(ptr);
			ptr = ptr->left;
		}
		else
		{
			ptr = stk.top();
			stk.pop();
			cout<<ptr->info<<"\t";
			ptr = ptr->right;
		}
	}while(!stk.empty() || ptr!=NULL);
	cout<<endl;
}
int main()
{
	cout<<"To continue press y, to discontinue press n \n";
	char ch;
	int what,val;
	cin>>ch;
	while(ch == 'y')
	{
		cout<<"To enter values in tree, press 1\n";
		cout<<"To delete a node, press 2\n";
		cout<<"For in order traversal, press 3\n";
		cin>>what;
		switch(what)
		{
			case 1:
				{
					create_BST();
					break;
				}
			case 2:
				{
					search_del();
					break;
				}
			case 3:
				{
					inOrder_withoutRec();
					break;
				}
		}
		cout<<"To continue press y, to discontinue press n \n";
		cin>>ch;
	}
	return 0;
}
