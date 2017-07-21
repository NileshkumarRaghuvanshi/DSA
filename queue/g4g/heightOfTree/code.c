#include <stdio.h>
#include <malloc.h>
//#include "../genericqueue/linkedlistQ.h"
#include "../queueGeneric/linked_listQ.h"

struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};


struct tree_root {
	struct tree_node *root;
	int height;
};

struct tree_root * createTree() {

	struct tree_root *temp =  malloc(sizeof(struct tree_root));
	if(temp) {

		temp->root = NULL;
		temp->height = 0;
	}

	return temp;
}


struct tree_node *createTreeNode(int data) {

	struct tree_node *temp = malloc(sizeof(struct tree_node));
	if(temp) {
		temp->data = data;
		temp->left = temp->right = NULL;
	}

	return temp;
}


void print_inorder(struct tree_node *root) {

	if(root) {
		print_inorder(root->left);
		printf("%d ",root->data);
		print_inorder(root->right);
	}

}


int getHeightOfBinaryTree(struct tree_node *root) {

	int height = 0;
	struct queue_head *q = createQ();
	
	if(root) {
		enqueue(q,(DATA)root);
		enqueue(q,(DATA)NULL);
	}
	else
		return height;

	
	while(!isEmpty(q)) {

		struct tree_node *temp = (struct tree_node *)dequeue(q);
	
		if(temp == NULL) {
			if(!isEmpty(q)) {
				enqueue(q,(DATA)NULL);
				height++;
				continue;
			}
			else
				break;

		}

		if(temp->left) {
			enqueue(q,(DATA)temp->left);
		}

		if(temp->right) {
			enqueue(q,(DATA)temp->right);
		}
	}

	return height;
}


int max(int a, int b) {
	
	return a>b?a:b;
}

int getHeightOfTreeRecursive(struct tree_node *root) {

	if(!root)
		return 0;
	//if(!root->left || !root->right)
	//	return 1;

	return max(getHeightOfTreeRecursive(root->left) + 1 ,
			getHeightOfTreeRecursive(root->right) + 1);


}
int main() {

	struct tree_root *tree = createTree();
	tree->root = createTreeNode(10);
	tree->root->left = createTreeNode(20);
	tree->root->right = createTreeNode(30);
/*	tree->root->left->left = createTreeNode(40);
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(90);
	tree->root->right->right = createTreeNode(100);
	tree->root->left->left->left = createTreeNode(60);
	tree->root->left->right->left = createTreeNode(70);
	tree->root->left->left->left->left = createTreeNode(80);
	tree->root->left->left->left->left->left = createTreeNode(110);*/	
	print_inorder(tree->root);
	printf("\n");

	printf("Height is %d\n",getHeightOfBinaryTree(tree->root));
	printf("Height is %d\n",getHeightOfTreeRecursive(tree->root) -1);
	printf("\n");
	return 0;
}
