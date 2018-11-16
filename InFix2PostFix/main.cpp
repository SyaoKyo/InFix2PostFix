/****************************
 *                          *
 *  中缀表达式转后缀表达式  *
 *                          *
 ****************************/
#include <iostream>
#include <cstring>
using namespace std;

int getPriority(char op);
void infix2postfix(char infix[], char s2[], int &top2);

const int maxSize = 1000;

int main()
{
	char infix[maxSize], s2[maxSize];
	int top2 = -1;
	cin >> infix;
	infix2postfix(infix, s2, top2);
	cout << s2 << endl;
	return 0;
}

int getPriority(char op)
{
	if (op == '+' || op == '-')
		return 0;
	else
		return 1;
}

void infix2postfix(char infix[], char s2[], int &top2)
{
	char s1[maxSize];
	int top = -1, i = 0;
	while (infix[i] != '\0')
	{
		if (infix[i] >= '0'&&infix[i] <= '9')
			s2[++top2] = infix[i++];
		else if (infix[i] == '(')
		{
			s1[++top] = '(';
			i++;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			if (top == -1 || s1[top] == '(' || getPriority(infix[i]) > getPriority(s1[top]))
				s1[++top] = infix[i++];
			else
				s2[++top2] = s1[top--];
		}
		else if (infix[i] == ')')
		{
			while (s1[top] != '(')
				s2[++top2] = s1[top--];
			top--;
			i++;
		}
	}
	while (top != -1)
		s2[++top2] = s1[top--];
	s2[++top2] = '\0';
}