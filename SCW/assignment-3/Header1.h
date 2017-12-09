#pragma once
#include<iostream>

using namespace std;

template<class type>
struct node
{
	type val;
	node<type> *next;
};

template<class t>
class Stack
{
    private:
		node<t> *head;
		int len;
    public:
		Stack();
		void push(const t& str);
		t pop();
		bool isEmpty();
		int getLength();
		t getTop();
		int getSeq(const t &ch);
		void clearAll();
		void print();
		~Stack();
};

template<class t>
Stack<t>::Stack()
{
	head = NULL;
	len = 0;
}

template<class t>
void Stack<t>::push(const t& str)
{
	node<t> *newnode = new(node<t>);
	if (isEmpty())
	{
		head = newnode;
		newnode->val = str;
		newnode->next = NULL;
		len++;
	}
	else
	{
		node<t> *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		newnode->val = str;
		newnode->next = NULL;
		p->next = newnode;
		len++;
	}
}

template<class t>
t Stack<t>::pop()
{
	node<t> *p = head;
	if (!isEmpty())
	{
		if (getLength() == 1)
		{
			t tempstr = p->val;
			head = NULL;
			len--;
			return tempstr;
		}
		else
		{
			while (p->next->next != NULL)
			{
				p = p->next;
			}
			t tempstr = p->next->val;
			p->next = NULL;
			len--;
			return tempstr;
		}
	}
	else
	{
		throw "Stack is empty!";
	}
	
}

template<class t>
bool Stack<t>::isEmpty()
{
	if (len == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class t>
int Stack<t>::getLength()
{
	return len;
}

template<class t>
t Stack<t>::getTop()
{
	if (isEmpty())
	{
		throw "Stack is empty!";
	}
	else
	{
		node<t> *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		return p->val;
	}
}

template<class t>
int Stack<t>::getSeq(const t &ch)
{
	int s = 0;
	node<t> *p = head;
	while (p->val != ch)
	{
		p = p->next;
		s++;
	}
	return s;
}

template<class t>
void Stack<t>::clearAll()
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		while (!isEmpty())
		{
			pop();
		}
	}
}

template<class t>
void Stack<t>::print()
{
	node<t> *p = head;
	cout << "Stack contains:\n";
	cout << p->val << "->";
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->val << "->";
	}
	cout << "/" << endl;
}

template<class t>
Stack<t>::~Stack()
{
	if (head)
	{
		delete head;
	}
}