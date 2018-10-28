#include<iostream>
#include<string.h>
using namespace std;
class calculate
{
	int top,j,i;
	char stack[50];
	char postfix[50];
	char infix[50];
	public:
		calculate()
		{
			top = -1;
			j = 0;
			i = 0;
		}
		void input()
		{
			cout<<"Enter infix expression\n";
			cin>>infix;
			int len = strlen(infix);
			infix[len] = ')'; //because if at last any operator is left in stack, we've to insert it in postfix.(we've condition that if infix[i]==')' then pop things from stack till we get '(' in stack and pop '(' too.
			infix[len+1]='\0';
			top++;
			stack[top] = '(';
		}
		void check()
		{
			while(infix[i]!='\0')
			{
				if(isalpha(infix[i]))
					insertPostfix(infix[i]);
				else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
				{
					if(preced(infix[i]) <= preced(stack[top]))
					{
						while(preced(infix[i]) <= preced(stack[top]))
							pop();
						push(infix[i]);
					}
					else if(preced(infix[i]) > preced(stack[top]))
						push(infix[i]);
				}
				else if(infix[i] == '(')
				{
					top++;
					stack[top]=infix[i];
				}
				else if(infix[i] == ')')
				{
					while(stack[top]!='(')
					{	pop();  }
					pop();
				}
				i++;
			}
		}
		int preced(char ch)
		{
			if(ch == '^')
				return 3;
			else if(ch == '/' || ch == '*')
				return 2;
			else if(ch == '+' || ch == '-')
				return 1;
			else
				return 0;
		}
		void insertPostfix(char ch)
		{
			if(ch!='(' && ch!=')')
			{
				postfix[j] = ch;
				j++;
			}
		}
		void push(char ch)
		{
			top++;
			stack[top] = ch;
		}
		void pop()
		{
			insertPostfix(stack[top]);
			top--;
		}
		void show()
		{
			postfix[j]='\0';
			cout<<"Postfix is \n";
			cout<<postfix;
		}
};
int main()
{
	calculate c;
	c.input();
	c.check();
	c.show();
	return 0;
}
