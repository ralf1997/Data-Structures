#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
class eval
{
	char postfix[50];
	int stack[50],top,i,res;
	public:
		eval()
		{
			top=-1;
			i =0 ;
			cout<<"Enter postfix\n";
			cin>>postfix;
		}
		void push(int num)
		{
			top++;
			stack[top]=num;
		}
		int pop()
		{
			int x=stack[top];
			top--;
			return x;
		}
		void find()
		{
			while(postfix[i]!='\0')
			{
				if(isdigit(postfix[i]))
					res=postfix[i]-48;
				else
				{
					int B=pop();
					int A=pop();
					switch(postfix[i])
					{
						case '+':
							{
								res = A + B;
								break;
							}
						case '-':
							{
								res = A - B;
								break;
							}
						case '*':
							{
								res = A * B;
								break;
							}
						case '/':
							{
								res = A / B;
								break;
							}
						case '^':
							{
								res = pow(A,B);
								break;
							}
					}
				}
				push(res);
				i++;
			}
			cout<<stack[top];
		}
};
int main()
{
	eval e;
	e.find();
	return 0;
}
