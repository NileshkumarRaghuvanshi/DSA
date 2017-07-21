#include <stdio.h>
#include <malloc.h>



#include "tree.h"


typedef int DATA;

struct treeNode {

	DATA data;
	struct treeNode *left;
	struct treeNode *right;
};
	


tree_ptr create_tree() {
	printf("creating tree\n");

	struct treeNode *temp = (struct treeNode *)malloc(sizeof(struct treeNode));
	if(!temp) {
		printf("ERROR :  creating a tree Root node\n");
		return 0;
	}
	temp->data = -1;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void destroy_tree(tree_ptr root) {

	//printf("deleting tree\n");

	if(root) {

		destroy_tree(root->left);
		destroy_tree(root->right);
		printf("removing : %d\n",root->data);
		free(root);
	}
}


void insert_node(tree_ptr *root,int data) {

	if(*root) {
		printf("data alredy present\n");
		return;
	}
	else {

		tree_ptr temp = malloc(sizeof(struct treeNode));
		if(!temp) {
			printf("ERROR : allocating a new node\n");
			return;
		}
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		*root = temp;
		printf("data %d inserted\n",data);
	}
}
void get_depth(tree_ptr root) {




}

void print_tree(tree_ptr root) {

	if(root) {
		print_tree(root->left);
		printf("%d ",root->data);
		print_tree(root->right);
	}

}



int get_height_of_tree(tree_ptr root) {

	int left_height = 0;
	int right_height = 0;
	if(root) {
		left_height = get_height_of_tree(root->left);
		right_height = get_height_of_tree(root->right);
	}
	else
		return 0;

	if(left_height < right_height)
		return (right_height+1);
	else
		return (left_height+1);

}


int get_depth_of_node(tree_ptr root, DATA data) {
	
	int found = 0;


	if(root) {

		if(root->data == data) {
			printf("found data\n");
			return 1;
		}
		else {
			printf("No match with %d\n", root->data);
			found = get_depth_of_node(root->left,data);
			if(!found)
				found = get_depth_of_node(root->right,data);
		}	

		if(found) 
			return found +1;
	}

	return found;
}


int main() {

	printf("Welcome to tree code \n");
	tree_ptr root = create_tree();
	if(!root) {
		printf("ERROR : creating tree\n");
		return -1;
	}

	insert_node(&(root->left),30);
	insert_node(&(root->left->left),20);
	insert_node(&(root->right),40);	
	insert_node(&(root->left->right),50);	
	insert_node(&(root->right->left),60);
	insert_node(&(root->right->right),70);
	insert_node(&(root->left->left->left),80);
	insert_node(&(root->left->left->right),90);
	insert_node(&(root->right->left->right),100);
	

	print_tree(root);
	printf("height = %d\n",get_height_of_tree(root));
	printf("depth of 100 is %d\n",get_depth_of_node(root,100));
	printf("depth of 70 is %d\n",get_depth_of_node(root,70));
	printf("depth of 30 is %d\n",get_depth_of_node(root,30));
	destroy_tree(root);
	return 0;
}


