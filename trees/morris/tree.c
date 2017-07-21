/*
**Moris traversal
** while current is not NULL
** 	if current->left == NULL
**		print current node
**		current  = curren->right;
**	else
**		find the inorder predecesor of current and make current as a right pointer of it
**		current = current->left
**
** NOTE: Morris traversal undo all the changes done  for traversal and restore the tree to its original
**	 structure. The logic is simple as below
**	while traversing down the left if we see the right child of a node is current node itself
**	then print the current node and make the current node's right pointer to NULL
*/


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


void morris_traversal (struct treeNode *current) {
	printf("this is morris traversal\n");
	struct treeNode *pre;
	while(current) {
		if(!current->left) {
			//printf("there is no left child\n");
			printf("%d ",current->data);
			current = current->right;
		}
		else {
			//printf("There is left child, looking for inorder predecesor\n");
			pre = current->left;
 			while (pre->right != NULL && pre->right != current) 
				pre = pre->right;
			
			if(!pre->right) { //found the predecesor
				//printf("inorder predecesor for %d is %d\n",current->data, pre->data);
				pre->right = current;
				current = current->left;
			}
			else {
				//printf("restoring back the right child %d to NULL\n",pre->data);
				printf("%d ",current->data);
				current = current->right;
				pre->right = NULL;
			}
		}
	}

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

int main() {

	struct treeNode *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	root->left->right = create_node(50);
	
	print_tree(root);
	printf("\n");
	morris_traversal(root);
	printf("\n");
	delete_tree(root);

	return 0;
}
