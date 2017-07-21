#include <iostream>
#include "tree.h"
#include "treeNode.h"
using namespace std;

int main() {

	cout <<"Namste!!!"<<endl;
	Tree *treePtr = new Tree();
	if(treePtr->insertNode(treePtr->getHead(),24))
		cout<<"Node added successfully"<<endl;
	else
		cout << "Error adding a node"<<endl;
	return 0;
}

