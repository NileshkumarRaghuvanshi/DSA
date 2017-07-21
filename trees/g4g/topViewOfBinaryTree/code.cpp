#include <cstdio>
#include <malloc.h>
#include "../../../cplusplus/queueLib/queuelib.h"
#include <iostream>

#include <map>

using namespace std;

typedef int DATA;

struct tree_node {
	
	DATA data;
	int hd;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_root {
	struct tree_node *root;
};


struct tree_node* createTreeNode(DATA data) {

	struct tree_node *temp = (struct tree_node *)malloc(sizeof(struct tree_node));
	if(temp) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}

	return temp;	

}


struct tree_root* createTree() {

	struct tree_root *temp = (struct tree_root *)malloc(sizeof(struct tree_root));
	if(temp) {

		temp->root = NULL;
	}

	return temp;
}

void _printTree(struct tree_node *root) {

	if(root) {
		_printTree(root->left);
		printf("%d ",root->data);
		_printTree(root->right);
	}
}

void printTree(struct tree_root *tree) {

	_printTree(tree->root);
	printf("\n");
}

void _deleteTree(struct tree_node *root) {

	if(!root) 
		return;

	_deleteTree(root->left);
	_deleteTree(root->right);

	free(root);
}


void deleteTree(struct tree_root *tree) {


	_deleteTree(tree->root);
	free(tree);

}


void printTopView(struct tree_node *root) {


	if(root) {

		map<int, int> level;

		struct myQueue *q = createQueue();

		enQueue(&q,(long)root);

		root->hd =0;
		level[root->hd] = root->data;
		while(!isQueueEmpty(&q)) {

			struct tree_node *temp = (struct tree_node *)deQueue(&q);
			
			if(temp->left) {
				temp->left->hd = temp->hd-1;
				
				if(level.find(temp->left->hd) == level.end())
					level[temp->left->hd] = temp->left->data;
				
				enQueue(&q,(long)temp->left);
			}

			if(temp->right) {
				temp->right->hd = temp->hd+1;

				if(level.find(temp->right->hd) == level.end())
					level[temp->right->hd] = temp->right->data;
				
				enQueue(&q,(long)temp->right);
			}
		}
		
		map<int, int> ::iterator it = level.begin();
		cout << "map size " <<level.size()<<endl;

		for(;it!=level.end();it++) {
			cout << "key :"<<it->first<<" val :"<<it->second<<endl;
		}
	}	
}

int main() {

	struct tree_root *tree = createTree();

	if(!tree) {
		printf("ERROR : creating tree root\n");
		return -1;
	}

	tree->root = createTreeNode(10);
	tree->root->left = createTreeNode(20);
	tree->root->right = createTreeNode(30);
	tree->root->left->left = createTreeNode(40);
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(80);

	printTree(tree);

	printTopView(tree->root);

	deleteTree(tree);
	return 0;
}
