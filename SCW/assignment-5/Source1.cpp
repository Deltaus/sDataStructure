#include<iostream>
#include"Header1.h"

using namespace std;

typedef char type;

binaryTreeNode* buildBinaryTree(type* post, type* in, int len)
{
	if (post == NULL || in == NULL || len <= 0)
	{
		return NULL;
	}
	type rootVal = post[len - 1];
	binaryTreeNode*  root = new binaryTreeNode();
	root->val = rootVal;
	root->left = NULL;
	root->right = NULL;
	int leftlen, rightlen;
	leftlen = 0;
	rightlen = 0;
	int count = 0;
	while (count < len && in[count] != rootVal)
	{
		count++;
	}
	leftlen = count;
	rightlen = len - leftlen - 1;
	if (leftlen > 0)
	{
		root->left = buildBinaryTree(post, in, leftlen);
	}
	if (rightlen > 0)
	{
		root->right = buildBinaryTree(post + leftlen, in + len - rightlen, rightlen);
	}
	return root;
}

int height(binaryTreeNode* root)
{
	if (root == NULL) return -1;
	int u = height(root->left);
	int v = height(root->right);
	return u>v ? u + 1 : v + 1;
}

void markLevel(binaryTreeNode* root,int ht)
{
	if (root == NULL)
	{
		return;
	}
	root->level = ht;
	markLevel(root->left, ht+1);
	markLevel(root->right, ht+1);
}

void printNodes(binaryTreeNode* root, int lev)
{
	if (root == NULL)
	{
		return;
	}
	if (root->level == lev)
	{
		cout << root->val;
	}
	else
	{
		printNodes(root->left, lev);
		printNodes(root->right, lev);
	}
}

void printBinaryTree(binaryTreeNode* root ,int ht)
{
	for (int i = 0; i <= ht; i++)
	{
		printNodes(root, i);
		cout << endl;
	}
}

int main()
{
	type* post = "HDFBKGCEA";
	type* in = "HBDFAEKCG";
	int length = strlen(post);
	binaryTreeNode* root = buildBinaryTree(post, in, length);
	const int TOTAL_HEIGHT = height(root);
	markLevel(root, 0);
	printBinaryTree(root, TOTAL_HEIGHT);
	system("Pause");
	return 0;
}