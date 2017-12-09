#include<iostream>
#include"Header1.h"

using namespace std;

int main()
{
	int a;
	int v, p;

	//cout << "Enter length:";
	//cin >> a;
	a = 6;
	int v1[] = { 45,4,2,1,4,3 };
	int p1[] = { 0,3,4,5,-2,-4 };
	int *cof = v1;
	int *pows = p1;
	SLList list1;
	for (int i = 0; i < a; i++)
	{
		list1.addNode(cof[i],pows[i]);
		//cout << list1.getSize() << endl;
	}
	list1.display();
	cout << endl;

	//cout << "Enter length:";
	//cin >> a;
	a = 5;
	int v2[] = { 12,3,4,3,2 };
	int p2[] = { 0,2,4,6,7 };
	cof = v2;
	pows = p2;
	SLList list2;
	for (int i = 0; i < a; i++)
	{
		list2.addNode(cof[i], pows[i]);
		//cout << list2.getSize() << endl;
	}
	list2.display();
	cout << endl;

	SLList addresult = list1 + list2;
	cout << "Result of list1 + list2:\n";
	addresult.display();
	cout << endl;

	int len = list1.getHighestPow() -list1.getLowestPow() + list2.getHighestPow() - list2.getLowestPow() + 1;
	int pow = list1.getLowestPow() + list2.getLowestPow();
	float* mulresult = list1 * list2;
	cout << "Result of list1 * list2:\n";
	for (int i = 0; i < len-1; i++)
	{
		cout << mulresult[i] << "x^" << pow << " + ";
		pow++;
	}
	cout << mulresult[len - 1] << "x^" << list1.getHighestPow() + list2.getHighestPow() << endl;
	cout << endl;

	int x;
	cout << "Enter a power to delete the item in list1:\n";
	cin >> x;
	list1.findAndDelete(x);
	list1.display();

	system("Pause");
	return 0;
}