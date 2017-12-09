#include<iostream>
#include<sstream>
#include"Header1.h"

using namespace std;

int isnum(const char &ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	else  return 0;
}

int ch2int(const char &ch)
{
	int num = ch - '0';
	return num;
}

char int2ch(const int &num)
{
	char ch = (char)(num + '0');
	return ch;
}

int priority(const char &ch)
{
	int p;
	switch (ch)
	{
	case '+': p = 0; break;
	case '-': p = 0; break;
	case '*': p = 1; break;
	case '/': p = 1; break;
	}
	return p;
}

int op_compare(const char &opin, const char &opout)
{
	if (opout == '(' || opin == '(')
	{
		return 1;
	}

	else
	{
		int in_op = priority(opin);
		int out_op = priority(opout);
		if (in_op == out_op)    //equal - 0/in < out - 1/in > out - -1
		{
			return 0;
		}
		else if (in_op < out_op)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

float calculate(const int &opr1, const char &op, const int &opr2)
{
	float ans;
	switch (op)
	{
	case '+': ans = opr1 + opr2; break;
	case '-': ans = opr1 - opr2; break;
	case '*': ans = opr1 * opr2; break;
	case '/': 
	{
		float o1 = (float)opr1;
		float o2 = (float)opr2;
		if (opr2 == 0)
		{
			throw "Divided by zero!";
		}
		else
		{
			ans = o1 / o2;
		}
	}break;
	}
	return ans;
}

int infixCal(const string &str)               //中缀直接计算
{
	Stack<char> numStack = Stack<char>();
	Stack<char> opStack = Stack<char>();
	opStack.push('#');

	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (ch == ' ')
		{
			continue;
		}
		if (!isnum(ch))
		{
			if (ch == '(')
			{
				numStack.push(ch);
			}
			else if (ch == ')')
			{
				char ch1 = numStack.pop();
				char ch2 = numStack.pop();
				char cop = opStack.pop();
				int num1 = ch2int(ch1);
				int num2 = ch2int(ch2);
				int ans = (int)calculate(num2, cop, num1);
				numStack.pop();
				numStack.push(int2ch(ans));
				while (opStack.getTop() == '*' || opStack.getTop() == '/')
				{
					ch1 = numStack.pop();
					ch2 = numStack.pop();
					cop = opStack.pop();
					num1 = ch2int(ch1);
					num2 = ch2int(ch2);
					ans = (int)calculate(num2, cop, num1);
					numStack.push(int2ch(ans));
				}
			}
			else
			{
				opStack.push(ch);
			}
		}
		else
		{
			if (opStack.getTop() == '#' || opStack.getTop() == '+' || opStack.getTop() == '-')
			{
				numStack.push(ch);
			}
			else
			{
				if (opStack.getTop() == '*' || opStack.getTop() == '/')
				{
					char tmp = numStack.getTop();
					if (tmp == '(')
					{
						numStack.push(ch);
					}
					else
					{
						char ch2 = numStack.pop();
						char op = opStack.pop();
						int num1 = ch2int(ch);
						int num2 = ch2int(ch2);
						int ans = calculate(num2, op, num1);
						numStack.push(int2ch(ans));
					}
				}
			}
		}
	}
	if (numStack.getLength() > 1)
	{
		while (numStack.getLength() != 1)
		{
			char ch1 = numStack.pop();
			char ch2 = numStack.pop();
			char cop = opStack.pop();
			int num1 = ch2int(ch1);
			int num2 = ch2int(ch2);
			int ans = (int)calculate(num2, cop, num1);
			numStack.push(int2ch(ans));
		}
	}
	return ch2int(numStack.pop());
}

string infix2Postfix(const string &str)         //中缀转后缀
{
	string result = "";
	Stack<char> stack = Stack<char>();
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (ch == ' ')
		{
			continue;
		}
		if (isnum(ch))
		{
			result += ch;
		}
		else
		{
			if (stack.isEmpty())
			{
				stack.push(ch);
			}
			else
			{
				if (ch == '(')
				{
					stack.push(ch);
				}
				else if (ch == ')')
				{
					char optmp = stack.pop();
					while (optmp != '(')
					{
						result += optmp;
						optmp = stack.pop();
					}
				}
				else
				{
					char top = stack.getTop();
					int prio = op_compare(top, ch);
					if (prio > 0)
					{
						stack.push(ch);
					}
					else if (prio <= 0)
					{
						while (prio <= 0)
						{
							try
							{
								result += stack.pop();
								top = stack.getTop();
								prio = op_compare(top, ch);
							}
							catch (char *s)
							{
								prio = 1;
							}
						}
						stack.push(ch);
					}
				}
			}
		}
	}
	if (!stack.isEmpty())
	{
		while (!stack.isEmpty())
		{
			result += stack.pop();
		}
	}
	return result;
}

float postfixCal(const string &str)             //后缀直接计算
{
	int len = str.length();
	float result;
	Stack<float> stack = Stack<float>();

	for (int i = 0; i < len; i++)
	{
		char tmp = str[i];
		if (isnum(tmp))
		{
			float num = (float)ch2int(tmp);
			stack.push(num);
		}
		else
		{
			float opr1 = stack.pop();
			float opr2 = stack.pop();
			result = calculate(opr2, tmp, opr1);
			stack.push(result);
		}
	}
	return result;
}


int main()
{
	string str1 = "5 + 4 * 3 + (9 - 4 * 6) * 8";
	string str2 = "5 * 6 + (7 * 2 - 8) * (2 - 5) + 6 * 5";
	cout << "Expression 1: " << str1 << endl;
	cout << "Expression 2: " << str2 << endl;

	int ans1 = infixCal(str1);
	float ans2 = postfixCal(infix2Postfix(str1));
	cout << "Calculated by infix expression: Ans = " << ans1 << endl;
	cout << "Calculated by postfix expression: Ans = " << ans2 << endl;

	ans1 = infixCal(str2);
	ans2 = postfixCal(infix2Postfix(str2));
	cout << "Calculated by infix expression: Ans = " << ans1 << endl;
	cout << "Calculated by postfix expression: Ans = " << ans2 << endl;
	system("Pause");
	return 0;
}