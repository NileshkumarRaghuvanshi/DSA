#include "tree.h"
#include <iostream>

using namespace std;


Tree::~Tree() {
	cout<<"Tree destructor"<<endl;
}

TreeNode* Tree::getHead() {
	if(!head) {
		head = new Tree();
		if(!head)
			cout<<"error allocating memory"<<endl;
		//head->setLeft(0);
		//head->setRight(0);
	}
	
	return head;	
}
int Tree::insertNode(Tree *head, DATA data) {

	int ret = true;
	cout<<"inserting a node = "<<data<<endl;

	return ret;


}

void Tree::deleteTree(Tree *head) {
	cout <<"deleting tree"<<endl;
	if(head) {
		//deleteTree(head->getLeft());
		//deleteTree(head->getRight());
		delete head;
	}
}
