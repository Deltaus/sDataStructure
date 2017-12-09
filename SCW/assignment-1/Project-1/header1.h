#pragma once
#include<iostream>
#include<math.h>

using namespace std;

template<class T>
class vector {
private:
	int dim;
	T* vect;
public:
	vector();
	vector(int l);
	vector(const vector<T>& v);
	vector(int len, const T* arr);

	vector<T> operator+(const vector<T>& v);
	vector<T> operator-(const vector<T>& v);
	T dot(const vector<T>& v);
	vector<T> cross(const vector<T>& v);

	int getDimension() const;
	T getNthEntry(int n) const;
	void setNthEntry(int n,T val) const; 
	vector<T> & operator=(vector<T>& obj);
	//friend ostream& operator<<(ostream &out, const vector &obj);
	//friend istream& operator>>(istream &in, const vector &obj);

	~vector();
};
template<class T>
vector<T>::vector()
{
	dim = 1;
	vect = new T[1];
	vect[0] = 0;
}
template<class T>
vector<T>::vector(int l)
{
	if (l <= 0)
	{
		throw "Invalid input!";	
	}
	dim = l;
	vect = new T[l];
	for (int i = 0; i<l; i++)
	{
		vect[i] = 0;
	}
}
template<class T>
vector<T>::vector(const vector<T>& v)
{
	dim = v.getDimension();
	vect = new T[dim];
	for (int i = 0; i < dim; i++)
	{
		vect[i] = v.getNthEntry(i);
	}
}
template<class T>
vector<T>::vector(int len, const T* arr)
{
	dim = len;
	vect = new T[len];
	for (int i = 0; i < dim; i++)
	{
		vect[i] = arr[i];
	}
}
template<class T>
vector<T> vector<T>::operator+(const vector<T>& v)
{
	if (dim != v.getDimension())
	{
		throw "Dimension doesn't match!";
	}
    vector<T> tempv = vector(dim);
	T val = 0;
	for (int i = 0; i < dim; i++)
	{
		val = vect[i];
		val += v.getNthEntry(i);
		tempv.setNthEntry(i, val);
	}
	return tempv;
}
template<class T>
vector<T> vector<T>::operator-(const vector<T>& v)
{
	if (dim != v.getDimension())
	{
		throw "Dimension doesn't match!";
	}
	vector<T> tempv = vector(dim);
	T val = 0;
	for (int i = 0; i < dim; i++)
	{
		val = vect[i];
		val -= v.getNthEntry(i);
		tempv.setNthEntry(i, val);
	}
	return tempv;
}
template<class T>
T vector<T>::dot(const vector<T>& v)
{
	T sum = 0;
	if (dim != v.getDimension())
	{
		throw "Dimension doesn't match!";
	}
	for (int i = 0; i < dim; i++)
	{
	    T temp = 0;
		temp = vect[i];
		temp *= v.getNthEntry(i);
		sum += temp;
	}
	return sum;
}
template<class T>
vector<T> vector<T>::cross(const vector<T> & v)
{
	if (dim == 3 && v.getDimension() == 3)
	{
		vector<T> tempv = vector(dim);
		tempv.setNthEntry(0, vect[1]*v.getNthEntry(2) - vect[2]*v.getNthEntry(1));
		tempv.setNthEntry(1, vect[2]*v.getNthEntry(0) - vect[0]*v.getNthEntry(2));
		tempv.setNthEntry(2, vect[0]*v.getNthEntry(1) - vect[1]*v.getNthEntry(0));
		return tempv;
	}
	else
	{
		throw "Cross product doesn't exist!";
	}
}
template<class T>
int vector<T>::getDimension() const
{
	return dim;
}
template<class T>
T vector<T>::getNthEntry(int n) const
{
	return vect[n];
}
template<class T>
void vector<T>::setNthEntry(int n, T val) const
{
	vect[n] = val;
}
template<class T>
vector<T> & vector<T>::operator=(vector<T>& obj)
{
	if (vect)
	{
		delete [] vect;
	}
	if (obj.getDimension() > 0)
	{
		vect = new T[obj.getDimension()];
		for (int i = 0; i < obj.getDimension(); i++)
		{
			vect[i] = obj.getNthEntry(i);
		}
	}
	else
	{
		vect = 0;
	}
	dim = obj.getDimension();
	return *this;
}
template<class T>
ostream& operator<<(ostream &out, const vector<T> &obj)
{
	out << "(" << obj.getNthEntry(0);
	for (int i = 1; i<obj.getDimension(); i++)
	{
		out << "," << obj.getNthEntry(i);
	}
	out << ")\n";
	return out;
}
template<class T>
istream& operator>>(istream &in, vector<T> &obj)
{
	cout << "Enter the values:\n";
	for (int i = 0; i < obj.getDimension(); i++)
	{
		T val;
		in >> val;
		obj.setNthEntry(i, val);
	}
	return in;
}
template<class T>
vector<T>::~vector()
{
	if (vect)
	{
		delete [] vect;
	}
	
}

