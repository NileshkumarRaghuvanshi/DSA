#include <stdio.h>
#include <malloc.h>

typedef int DATA;

struct tree_node {
	
	DATA data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_root {
	struct tree_node *root;
};


struct tree_node* createTreeNode(DATA data) {

	struct tree_node *temp = malloc(sizeof(struct tree_node));
	if(temp) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}

	return temp;	

}


struct tree_root* createTree() {

	struct tree_root *temp = malloc(sizeof(struct tree_root));
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


void treeToDBList(struct tree_node *root, struct tree_node **prev, struct tree_node **head) {

	if(!root) {
		//printf("returning\n");
		return;
	}

	treeToDBList(root->left,prev,head);

	if(!(*head)) {
		//printf("updating head\n");
		*head = root;
	}
	else {
		if(prev) {
			//printf("connecting \n");
			(*prev)->right = root;
			root->left = (*prev);
		}
	}

	//printf("here\n");
	(*prev) = root;
	treeToDBList(root->right,prev,head);


}


void printDBList(struct tree_node *head) {


	while(head) {
		printf("%d ",head->data);
		head = head->right;
	}
	printf("done\n");
}


int main() {

	struct tree_root *tree = createTree();
	struct tree_node *head = NULL;
	struct tree_node *prev = NULL;
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

	
	treeToDBList(tree->root, &prev, &head);

	printDBList(head);
	//deleteTree(tree);
	return 0;
}
