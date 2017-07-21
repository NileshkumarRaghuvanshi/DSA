#include <stdio.h>
#include <malloc.h>


struct naryTree {
	int data;
	struct naryTree *sib;
	struct naryTree *child;
};


struct naryTree *createTreeNode(int data) {

	struct naryTree *temp = malloc(sizeof(struct naryTree));
	if(temp) {
		temp->data = data;
		temp->sib = NULL;
		temp->child = NULL;
	}
	return temp;
}


void printTree(struct naryTree *root) {

	if(!root)
		return;


	printf("%d ",root->data);
	printTree(root->sib);
	printTree(root->child);

}

void converToMirror(struct naryTree *root) {





}

		
int main() {


	struct naryTree *root = createTreeNode(10);
	root->child = createTreeNode(2);
	root->child->sib = createTreeNode(34);
	root->child->sib->sib = createTreeNode(56);
	root->child->sib->sib->sib = createTreeNode(100);
	root->child->sib->child = createTreeNode(1);
	root->child->sib->sib->sib->child = createTreeNode(7);
	root->child->sib->sib->sib->child->sib = createTreeNode(8);
	root->child->sib->sib->sib->child->sib->sib = createTreeNode(9);
	//root->child->sib->sib->sib->child = createTreeNode(7);

	printTree(root);
	printf("\n");


	convertToMirror(root);

	printTree(root);
	printf("\n");

	

	return 0;
}
