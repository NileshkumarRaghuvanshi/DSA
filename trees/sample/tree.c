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

int print_ancestor(struct treeNode *root, int data) {

	int found =0;
	if(root) {
		if(root->data == data) {
			printf("data found\n");
			return 1;
		}
		else {
			printf("No match @ %d\n",root->data);
			found = print_ancestor(root->left,data);
			if(!found)
				found = print_ancestor(root->right,data);

			if(found)
				printf("%d ",root->data);
		}

	}

}


int main() {

	struct treeNode *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	root->left->right = create_node(50);
	root->right->left = create_node(60);
	root->right->right = create_node(70);

	print_tree(root);
	printf("\n");

	print_ancestor(root,70);
	delete_tree(root);

	return 0;
}
