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
void search()
{
	BST *check = new BST;
	check = root;
	BST *parent = new BST;
	parent = NULL;
	int num;
	cout<<"Enter element you wanna search\n";
	cin>>num;
	while(1)
	{
		if(check->info == num)
		{
			if(parent == NULL)
			{
				cout<<"Element found at root\n";
			}
			else
			{
				cout<<"Parent is "<<parent->info<<endl;
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
		else
		{
			cout<<"Number not found\n";
			break;
		}
	}
}
void findMin()
{
	BST *check = new BST;
	check = root;
	while(check->left!=NULL)
	{
		check = check->left;
	}
	cout<<"Minimum element is "<<check->info<<endl;
}
void findMax()
{
	BST *check = new BST;
	check = root;
	while(check->right!=NULL)
	{
		check = check->right;
	}
	cout<<"Maximum element is "<<check->info<<endl;
}
void inOrder_withRec(BST *curr)
{
	if(root==NULL)
		return;
	if(curr!=NULL)
	{
		inOrder_withRec(curr->left);
		cout<<curr->info<<"\t";
		inOrder_withRec(curr->right);
	}
	cout<<endl;
}
void Level_order_traversing()
{
	BST *ptr ;
	queue <BST *> myqueue;
	myqueue.push(root);
	ptr = myqueue.front();
	while(!myqueue.empty())
	{
		myqueue.pop();
		cout<<ptr->info<<"\t";
		if(ptr->left != NULL)
			myqueue.push(ptr->left);
		if(ptr->right != NULL)  //we have to check both left and right, thats why we use if and if and not else.
			myqueue.push(ptr->right);
		ptr=myqueue.front();
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
void preOrder_withoutRec()
{
	BST *ptr;
	stack <BST *> mystack;
	mystack.push(root);
	while(!mystack.empty())
	{
		ptr = mystack.top();
		mystack.pop();
		cout<<ptr->info;
		if(ptr->right!=NULL)
			mystack.push(ptr->right);
		if(ptr->left!=NULL)
			mystack.push(ptr->left);
	}
	cout<<"\n";
}
int main()
{
	char ch;
	int what;
	cout<<"To continue press y and to discontinue press n\n";
	cin>>ch;
	while(ch!='n')
	{
		cout<<"To insert elements press 1\n";
		cout<<"To search an element press 2\n";
		cout<<"To find minimum element press 3\n";
		cout<<"To find maximum element press 4\n";
		cout<<"For level order traversing(left then right), press 5\n";
		cout<<"For InOrderTraversal without recursion, press 6\n";
		cout<<"For PreOrderTraversal without recursion, press 7\n";
		cout<<"For InOrderTraversal with recursion press 8\n";
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
					search();
					break;
				}
			case 3:
				{
					findMin();
					break;
				}
			case 4:
				{
					findMax();
					break;
				}
			case 5:
				{
					Level_order_traversing();
					break;
				}
			case 6:
				{
					inOrder_withoutRec();
					break;
				}
			case 7:
				{
					preOrder_withoutRec();
					break;
				}
			case 8:
				{
					inOrder_withRec(root);
					break;
				}
		}
		cout<<"To continue press y and to discontinue press n\n";
		cin>>ch;
	}
	return 0;
}
