#pragma once
#include<iostream>

using namespace std;

struct node
{
	   float val;                   //系数
	   int pow;                     //阶数
	   node *next;                  //指向下一项的指针
};

class SLList
{
    private:
		int count;                                   //多项式项数
		node *head;                                  //指向多项式首项的指针
    public:
		SLList();                                    //构造函数
		void insertEnd(float n, int pw);             //尾部插入项
		void addNode(float n,int pw);                //输入系数、阶数，增加该项到多项式
		void addNode(const node& nd);                //输入一项节点，增加该项到多项式
		void findAndDelete(int pw);                  //找到并删除对应阶数项   ----题目二 
		SLList operator+(SLList& tl);                //多项式加法
		float* operator*(SLList& tl);                //多项式乘法
		float getCoef(int pw);                       //输入阶数，获取该项系数
		node* getHead();                             //返回指向多项式首项的指针
		int getSize();                               //返回多项式项数
		int getHighestPow();                         //返回最高次项的次数
		int getLowestPow();                          //返回最低次项的次数
		void display();                              //显示多项式
};
 
SLList::SLList()
{
	count = 1;
	head = new(node);
	head->val = 0;
	head->pow = 0;
	head->next = NULL;
}

void SLList::insertEnd(float n, int pw)
{
	node *newnode = new(node);
	newnode->val = n;
	newnode->pow = pw;
	newnode->next = NULL;
	node *p = head;
	while ((*p).next != NULL)
	{
		p = (*p).next;
	}
	(*p).next = newnode;
	count++;
}

void SLList::addNode(float n, int pw)
{
	if (count == 1)
	{
		if (head->pow == 0 && head->val == 0)
		{
			head->val = n;
			head->pow = pw;
		}
		else
		{
			if (pw == head->pow)
			{
				head->val += n;
			}
			else
			{
				node *newnode = new(node);
				newnode->val = n;
				newnode->pow = pw;
				if (pw > head->pow)
				{
					newnode->next = head;
					head = newnode;
				}
				else
				{
					head->next = newnode;
					newnode->next = NULL;
				}
				count++;
			}
		}
	}
	else
	{
		node *p = head;
		if (pw > p->pow)
		{
			node *newnode = new(node);
			newnode->val = n;
			newnode->pow = pw;
			newnode->next = p;
			head = newnode;
			count++;
		}
		else if (pw == p->pow)
		{
			p->val += n;
		}
		else
		{
			while ((*p).next != NULL && (*p).next->pow > pw)
			{
				p = (*p).next;
			}
			if ((*p).next != NULL)
			{
				if ((*p).next->pow < pw)
				{
					node *newnode = new(node);
					newnode->val = n;
					newnode->pow = pw;
					newnode->next = (*p).next;
					(*p).next = newnode;
					count++;
				}
				else
				{
					(*p).next->val += n;
				}
			}
			else
			{
				this->insertEnd(n, pw);
			}
		}
	}
}

void SLList::addNode(const node& nd)
{
	addNode(nd.val, nd.pow);
}
 
void SLList::findAndDelete(int pw)
{
	if (count == 1)
	{
		if (head->pow == pw)
		{
			head->val = 0;
			head->pow = 0;
			head->next = NULL;
		}
		else
		{
			cout << "Not found..." << endl;
		}
	}
	else
	{
		node *p = head;
		if (pw > p->pow)
		{
			cout << "Not found..." << endl;
		}
		else if (pw == p->pow)
		{
			head = head->next;
			(*p).next = NULL;
			count--;
		}
		else
		{
			while ((*p).next != NULL && (*p).next->pow > pw)
			{
				p = (*p).next;
			}
			if ((*p).next != NULL)
			{
				if ((*p).next->pow < pw)
				{
					cout << "Not found..." << endl;
				}
				else
				{
					node* tp = (*p).next;
					p->next = tp->next;
					tp->next = NULL;
					count--;
				}
			}
			else
			{
				cout << "Not found..." << endl;
			}
		}
	}
}

SLList SLList::operator+(SLList& tl)
{
	SLList rst = SLList();
	node *p = head;
	while (p != NULL)
	{
		rst.addNode(p->val, p->pow);
		p = (*p).next;
	}
	const node *q = tl.getHead();
	while (q != NULL)
	{
		rst.addNode(q->val, q->pow);
		q = (*q).next;
	}
	delete q;
	return rst;
}
 
float* SLList::operator*(SLList& tl)
{
	int lenthis = this->getHighestPow() - this->getLowestPow() + 1;
	int lentl = tl.getHighestPow() - tl.getLowestPow() + 1;
	int num = lenthis + lentl - 1;
	int diff = this->getLowestPow() + tl.getLowestPow();
	float* mul = new float[num];
	for (int i = 0; i < num; i++)
	{
		mul[i] = 0;
	}
	int seq = 0;
	for (int i = this->getLowestPow(); i <= this->getHighestPow(); i++)
	{
		for (int j = tl.getLowestPow(); j <= tl.getHighestPow(); j++)
		{
			seq = i + j - diff;
			mul[seq] += this->getCoef(i) * tl.getCoef(j);
		}
	}
	return mul;
}

float SLList::getCoef(int pw)
{
	node* p = head;
	while (p != NULL && p->pow != pw)
	{
		p = (*p).next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return p->val;
	}
}
 
node* SLList::getHead()
{
	node *p = new(node);
	p = head;
	return p;
}

int SLList::getSize()
{
	return count;
}

int SLList::getHighestPow()
{
	return head->pow;
}

int SLList::getLowestPow()
{
	node* p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p->pow;
}

void SLList::display()
{
	int rm = count;
	cout << "The polynomial is:\n";
	node *p = head;
	while (p != NULL)
	{
		if (rm > 1 && count > 1)
		{
			if ((*p).pow > 0)
			{
				cout << (*p).val << "x^" << (*p).pow << " + " ;
			}
			else if ((*p).pow < 0)
			{
				cout << (*p).val << "x^(" << (*p).pow << ") + ";
			}
			else
			{
				cout << (*p).val << " + ";
			}
	    }
		else if(rm == 1 && count > 1)
		{
			if ((*p).pow > 0)
			{
				cout << (*p).val << "x^" << (*p).pow ;
			}
			else if ((*p).pow < 0)
			{
				cout << (*p).val << "x^(" << (*p).pow << ")";
			}
			else
			{
				cout << (*p).val ;
			}
		}
		else
		{
			if ((*p).pow > 0)
			{
				cout << (*p).val << "x^" << (*p).pow;
			}
			else if ((*p).pow < 0)
			{
				cout << (*p).val << "x^(" << (*p).pow << ")";
			}
			else
			{
				cout << (*p).val;
			}
		}
		p = (*p).next;
		rm--;
	}
	cout << endl;
}

