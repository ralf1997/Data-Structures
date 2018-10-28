#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class Evaluate
{
	int stack[50],top,i,res;
	char postfix[50];
	public:
		Evaluate()
		{
			top = -1;
			i = 0;
		}
		void input()
		{
			cout<<"Enter postfix expression that you wish to evaluate\n";
			cin>>postfix;
		}
		void push(int num)
		{
			top++;
			stack[top] = num;
		}
		int pop()
		{
			int x = stack[top];
			top--;
			return x;
		}
		void evaluateExp()
		{
			//int res;
			while(postfix[i] != '\0')
			{
				if(isdigit(postfix[i]))
					res = postfix[i] - 48;
				else
				{
					int B = pop();
					int A = pop();
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
				//cout<<stack[top];
			}
		}
		void display()
		{
			cout<<"The result is\n";
			cout<<stack[top];
		}
};
int main()
{
	Evaluate e;
	e.input();
	e.evaluateExp();
	e.display();
	return 0;
}
