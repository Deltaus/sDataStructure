#pragma once
#include<iostream>

typedef char type;
struct binaryTreeNode
{
	type val;
	binaryTreeNode *left, *right;
	int level;
};