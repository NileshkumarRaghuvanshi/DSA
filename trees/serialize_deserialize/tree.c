#include <stdio.h>
#include <malloc.h>

struct treeNode {
	int data;
	struct treeNode *left;
	struct treeNode *right;
};


struct treeNode * create_node(int data) {

	struct treeNode *temp = malloc(sizeof(struct treeNode));
	if (!temp) {
		printf("ERROR : creating a node!\n");
		return 0;
	}
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}


void delete_tree(struct treeNode *root) {
	if(root) {
		delete_tree(root->left);
		delete_tree(root->right);
		printf("removing %d\n",root->data);
		free(root);
	}
}

void print_tree(struct treeNode *root) {

	if(root) {
		print_tree(root->left);
		printf("%d ",root->data);
		print_tree(root->right);
	}
}


int is_BST(struct treeNode *root) {
	
	int _is_BST = 0;
	if(root) {
		if(root->left) {
			if(root->left->data < root->data) {
				printf("left < root\n");
				_is_BST = is_BST(root->left);
			}
			else 
				return 0;
		}
		if(root->right) {
			if(root->right->data > root->data) {
				printf("right > root\n");
				_is_BST &= is_BST(root->right);
			}
			else
				return 0;
		}
		
		if(!root->left && !root->right)
			return 1;
	}

	return _is_BST;
}
int main() {

	struct treeNode *root = create_node(50);
	root->left = create_node(30);
	root->right = create_node(60);
	root->left->left = create_node(20);
	root->left->right = create_node(80);
	root->right->left = create_node(55);
	root->right->right = create_node(70);

	
	print_tree(root);
	printf("\n");

	if(is_BST(root)) 
		printf("Tree is BST\n");
	else
		printf("tree is not BST\n");

	delete_tree(root);

	return 0;
}
