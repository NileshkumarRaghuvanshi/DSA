/** Jai Shri Ganesh **/
#include <stdio.h>
#include <malloc.h>


#include "tree.h"

//struct TreeNode node;

typedef struct treeNode {
	DATA data;
	int level;
	struct treeNode *left;
	struct treeNode *right;
} TreeROOT;

typedef struct treeCDT {
	TreeROOT *root;
}treeCDT;

#if 1

int AVLInsert(TreeADT *rootADT, DATA data) {

	//printf("Calling internal\n");
	if(!(*rootADT)) {
		printf("Adding a root node\n");
		*rootADT = malloc(sizeof(treeCDT));
		if(!(*rootADT)) {
			printf("Error allocating memory to root node\n");
			return -1;
		}
		else {
			(*rootADT)->root = NULL;
			return I_AVLInsert(&((*rootADT)->root),data);
		}
	}
	else
		return I_AVLInsert(&((*rootADT)->root),data);
}
int AVLRemove(TreeADT *rootADT, DATA data) {

	//printf("Calling internal\n");
        if(!(*rootADT)) {
                printf("tree is empy. nothing to remove!!!\n");
		return -1;
	}
        else
               return  I_AVLRemove((*rootADT)->root,data);
}


TreeADT createTree() {
	printf("Creating Tree\n");

}
void I_destroyTree(TreeROOT *rootNode);

void DestroyTree(TreeADT *rootADT) {
	printf("Destroying tree\n");
	I_destroyTree((*rootADT)->root);
}

void I_destroyTree(TreeROOT *rootNode) {

	if(rootNode) {
		I_destroyTree(rootNode->left);
		I_destroyTree(rootNode->right);
		printf("deleting %d \n",rootNode->data);
		free(rootNode);
	}
	

}

int getHeight(TreeROOT *node) {
	if(node)
		return node->level;
	else
		return 0;
}
int getBalance(TreeROOT *node) {
	return (getHeight(node->left) - getHeight(node->right));
}

int getMax(int a, int b) {
	
	return (a>b)?a:b;
	
}

void I_AVLRotateRight(TreeROOT **rootNode) {

	int rc = 0;
	printf("AVL right rotation\n");

        TreeROOT *k1 = *rootNode;
        printf("k1 = %d\n",k1->data);
        TreeROOT *k2 = k1->left;
        printf("k2 = %d\n",k2->data);
        TreeROOT *y = k2->right;
        if (y)
                printf("y = %d\n",y->data);

        //rotation
        *rootNode = k2;
        k2->right = k1;
        k1->left = y;

        //adjust height
        k1->level = getMax(getHeight(k1->left),getHeight(k1->right)) + 1;
        k2->level = getMax(getHeight(k2->left),getHeight(k2->right)) + 1;

}

void I_AVLRotateLeft(TreeROOT **rootNode) {

	printf("AVL left rotation\n");
	TreeROOT *k1 = *rootNode;
	printf("k1 = %d\n",k1->data);
	TreeROOT *k2 = k1->right;
	printf("k2 = %d\n",k2->data);
	TreeROOT *y = k2->left;
	if (y)
		printf("y = %d\n",y->data);

	//rotation
	*rootNode = k2;
	k2->left = k1;
	k1->right = y;

	//adjust height
	k1->level = getMax(getHeight(k1->left),getHeight(k1->right)) + 1;
	k2->level = getMax(getHeight(k2->left),getHeight(k2->right)) + 1;

}

int I_AVLInsert(TreeROOT **rootNode, DATA data) {

	//printf("Calling internal AVL insert functions!!!\n");
	int rc;
	if(!(*rootNode)) {
		 TreeROOT *newNode = malloc(sizeof(TreeROOT));
		if(!newNode) {
			printf("Error allocating memory to new node!!!\n");
			return -1;
		}
		else {
			//printf("memory for the new node allocted\n");
			newNode->data = data;
			newNode->level = 1;
			newNode->left = newNode->right = NULL;
		}

		*rootNode = newNode;
		return 1;
	}
	else if(data > (*rootNode)->data){
		//printf("going right\n"); 
		rc = I_AVLInsert(&((*rootNode)->right),data);
	}
	else if (data < (*rootNode)->data) {
		//printf("going left\n"); 
		rc = I_AVLInsert(&((*rootNode)->left),data);
	}
	else
		printf("duplicate data and hence canceling it\n");
		
	if(rc > 0) {
		//printf("checking for the balance\n");
		(*rootNode)->level =getMax(getHeight((*rootNode)->left),getHeight((*rootNode)->right)) + 1;
		
		signed int bal = getBalance(*rootNode);
		printf("bal = %d\n",bal);

		if(bal == 2 && data < ((*rootNode)->left->data)) {
			printf("Need to rotate node = %d to right\n",(*rootNode)->data);
			I_AVLRotateRight(rootNode);
		}
		else if(bal == 2 && data > ((*rootNode)->left->data)) {
			printf("Need to rotate node = %d to left\n",(*rootNode)->left->data);
			I_AVLRotateLeft(&((*rootNode)->left));
			printf("Need to rotate node = %d to right\n",((*rootNode)->data));
			I_AVLRotateRight(rootNode);
		}
		else if(bal == -2 && data < ((*rootNode)->right->data)) {
			printf("Need to rotate node = %d to right\n",(*rootNode)->right->data);
			I_AVLRotateRight(&((*rootNode)->right));
			printf("Need to rotate node = %d to left\n",(*rootNode)->data);
			I_AVLRotateLeft(rootNode);
		}
		else if((bal == -2) && (data > ((*rootNode)->right->data))) {
			printf("Need to rotate node = %d to left\n",(*rootNode)->data);
			I_AVLRotateLeft(rootNode);
		}
		else
			printf("No rotation at = %d \n",(*rootNode)->data);

	}
	else
		printf("negative rc\n");

	return rc;
}
int I_AVLRemove(TreeROOT *rootNode, DATA data) {

	printf("Calling internal AVL remove function!!!\n");
	return 1;
}

void I_printAVLTree(TreeROOT *rootNode) {

	if(rootNode) {
		I_printAVLTree(rootNode->left);
		printf("%d ",rootNode->data);
		printf("Level = %d\n",rootNode->level);
		I_printAVLTree(rootNode->right);
	}
	//else
	//	printf("No data\n");
}
void PrintAVLTree(TreeADT *rootADT) {
	if(*rootADT) {
		printf("printing nodes\n");
		I_printAVLTree((*rootADT)->root);
	}
	else
		printf("tree is empty nothing to print\n");
}

#endif
