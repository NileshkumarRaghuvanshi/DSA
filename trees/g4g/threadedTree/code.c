#include <stdio.h>

#define DATA long

struct threadedNode {

	DATA data;
	int rTag;
	int lTag;
	struct threadedNode *left;
	struct threadedNode *right;
};


struct thrededTree {
	
	struct threadedNode *root;
};


struct threadedNode * createThreadedNode(DATA data) {
	
	struct threadedNode *temp =  (struct threadedNode *)malloc(sizeof(struct threadedNode));
	if(temp) {
		temp->data = data;
		temp->rTag = 0;
		temp->lTag = 0;
		temp->left = temp->right = NULL;
	}

	return temp;
}

struct threadedTree* createThreadedTree() {

	struct threadedTree *temp = (struct threadedTree *)(sizeof(struct threadedTree));
	if(temp) {
		temp->root = NULL;
	}

	return temp;
}

void insertNode(struct threadedNode *root, struct threadedNode *pos, DATA data) {

	struct threadedNode *temp = createThreadedNode(data);

	if(root) {

		

	}
	else {
	
		root = temp;
	}


}


int main() {

	struct threadedTree *tree = createThreadedTree();
	if(!tree) {
		return -1;
	}

	insertNode(tree->root,tree->root,10);

	return 0;
}
