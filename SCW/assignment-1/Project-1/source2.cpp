#include<iostream>
#include<math.h>
#include<stdlib.h>
#include"header1.h"

using namespace std;

int main()
{
	vector<double> v1, v2, v3, v4, v5;
	v2 = vector<double>(2);
	v3 = vector<double>(3);
	v4 = vector<double>(6);
	try
	{
		v5 = vector<double>(-1);
	}
	catch (char *s)
	{
		cout << s << endl;
		v5 = vector<double>();
	}
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << v4 << endl;
	cout << v5 << endl;
	cin >> v1;
	cin >> v2;
	cin >> v3;
	cout << v1;
	cout << v2;
	cout << v3;
	try
	{
		cout << v1 + v3;
	}
	catch (char *s)
	{
		cout << s << endl;
		v1 = vector<double>(v3.getDimension());
		cin >> v1;
		cout << v1 + v3;
	}
	cout << v1.dot(v3) << endl;
	cout << v1.cross(v3) << endl;
	cout << v3.cross(v1) << endl;
	v5 = vector<double>(6);
	double a1[] = { 1,2,3,4,5,8.9 };
	double a2[] = { 3.6,7,1.8,3,1,9.0 };
	v4 = vector<double>(6,a1);
	v5 = vector<double>(6,a2);
	cout << v4 + v5 << endl;
	try
	{
		cout << v4.dot(v5)<<endl;
		cout << v4.cross(v5) << endl;;
	}
	catch (char*s)
	{
		cout << s << endl;
	}
	system("Pause");
	return 0;
}