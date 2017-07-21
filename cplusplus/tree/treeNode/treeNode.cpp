#include "treeNode.h"

TreeNode :: TreeNode() {
	cout << "TreeNode constructor"<<endl;
	left = 0;
	right = 0;
}
void TreeNode::setLeft(TreeNode *ptr) { left = ptr;}
void TreeNode::setRight(TreeNode *ptr ) { right = ptr;}
