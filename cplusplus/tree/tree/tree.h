#ifndef TREE_H
#define TREE_H

#include "treeNode.h"

class Tree : public TreeNode {

public:
	Tree() {
		cout<<"Tree constructor"<<endl;
		head = 0;
	}
	~Tree();
	TreeNode* getHead();
	int insertNode(Tree *head, DATA data);
	void deleteTree(Tree *head);
private:
	TreeNode *head;

};


#endif

