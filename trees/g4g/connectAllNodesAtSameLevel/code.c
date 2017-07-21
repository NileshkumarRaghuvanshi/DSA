#include <stdio.h>
#include <malloc.h>

typedef int DATA;

struct tree_node {
	
	DATA data;
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *next;
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
		temp->next = NULL;
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


struct tree_node *getRightNodeAtSameLevel(struct tree_node *parent, struct tree_node *node) {



}
void connectNodesAtSameLevel(struct tree_node *root1) {


	struct tree_node *root = root1;
	while(root) {
		if(!root)
			return;

		if(root->left) {
		
			root->left->next = root->right;
			if(!root->left->next) {
				struct tree_node *temp = root->next;
				while(temp) {
					if(temp->left) {
						temp = temp->left;
						break;
					}
					if(temp->right) {
						temp = temp->right;
						break;
					}

					temp = temp->next;
					printf("going right\n");
				}

				root->left->next = temp;
			}
			printf("connecting %d with %d\n",root->left->data,root->left->next?root->left->next->data:0);
		}

		if(root->right) {

			if(root->next)
				root->right->next = root->next->left;
			if(!root->right->next) {
				struct tree_node *temp = root->next;
				while(temp) {

					if(temp->left) {
						temp = temp->left;
						break;
					}
					if(temp->right) {
						temp = temp->right;
						break;
					}

					temp = temp->next;

				}
				root->right->next = temp;
			}
			printf("connecting %d with %d\n",root->right->data,root->right->next?root->right->next->data:0);

		}


		//connectNodesAtSameLevel(root->left);
		//connectNodesAtSameLevel(root->right);

		if(root->next)
			root = root->next;
		else {
			root1 = root1->left;
			root = root1;
		}

	}
}


void printConnectedNodes(struct tree_node *root) {

	while(root) {

		struct tree_node *temp = root;
		while(temp) {
			printf("%d ",temp->data);
			temp = temp->next;
		}

		root = root->left;
		
	}

	printf("\n");

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
	tree->root->left->left->right = createTreeNode(90);
	//tree->root->right->right->right = createTreeNode(90);
	//tree->root->left->left->left = createTreeNode(80);
	//tree->root->right->right->right = createTreeNode(90);
	tree->root->right->right->right = createTreeNode(150);
	printTree(tree);

	connectNodesAtSameLevel(tree->root);
	printf("done\n");
	printConnectedNodes(tree->root);
	deleteTree(tree);
	return 0;
}
