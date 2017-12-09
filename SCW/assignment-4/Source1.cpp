#include<iostream>

using namespace std;

void GetNext(char* p, int* next)
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{  
		if (k == -1 || p[j] == p[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int kmp(char *tarstr, char *pattern)
{
	if (tarstr == NULL || pattern == NULL)
		return -1;

	int tarlen = strlen(tarstr);
	int patlen = strlen(pattern);
	int *pna = new int[patlen];
	GetNext(pattern,pna);

	cout << "NEXT Array:" << endl;
	for (int i = 0; i < patlen; ++i)
		cout << pattern[i] << "\t" << pna[i] << endl;

	cout << "Process:" << endl;
	int curPos = 0;
	int head = 0;
	cout << "Pos: " << head << endl;
	for (int i = 0; i < tarlen; )
	{
		if (pattern[curPos] == tarstr[i])
		{
		    i++;
			curPos++;
		}
		else
		{
			if (curPos == 0)
			{
				i++;
				head++;
				cout << "Pos: " << head << endl;
			}
			else
			{
				int step = curPos - pna[curPos - 1];
				head += (step - 1);
				cout << "Pos: " << head << endl;
				i += step;
				curPos = 0;
			}
		}
		if (curPos == patlen)
		{
			delete[] pna;
			return i - patlen;
		}
	}
	delete[] pna;
	return -1;
}

int main()
{
	char tarstr[] = "abgvgaaabbaaabcxaabbabcabaacbacba";
	char pattern[] = "aaab";
	cout << "Found! Pos:" << kmp(tarstr, pattern) << endl;

	system("Pause");
}