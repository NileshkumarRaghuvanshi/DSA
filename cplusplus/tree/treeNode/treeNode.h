#ifndef TREENODE_H
#define TREENODE_H
#include "nodeData.h"
#include <iostream>

using namespace std;

class TreeNode : public nodeData {

public:
	TreeNode();
	void setLeft(TreeNode *ptr);
	void setRight(TreeNode *ptr);

	TreeNode *getLeft() { return left; }
	TreeNode *getRight() { return right; }

private:
	TreeNode *left;
	TreeNode *right;
};

#endif

