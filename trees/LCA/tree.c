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

int find_LCA(struct treeNode *root,int a,int b) {

	int left,right;
	if(!root) {
		printf("NULL!!!\n");
		return 0;
	}

	if(((a^(root->data)) == 0)) {
		printf("Found one a = %d\n",root->data);
		return root->data;
	}
	if(((b^(root->data)) == 0)) {
		printf("Found one b = %d\n",root->data);
		return root->data;
	}

	left = find_LCA(root->left,a,b);
	right = find_LCA(root->right,a,b);

	if((left^a^b^right) == 0) {
		printf("found LCA =%d\n",root->data);
		return root->data;
	}
	else if(left) {
		printf("returning left = %d\n",left);
		return left;
	}
	else if(right) {
		printf("returning right = %d\n",right);
		return right;
	}
	else {
		printf("returning zero\n");
		return 0;
	}

}
int main() {

	int lca;
	struct treeNode *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	root->left->right = create_node(50);
	root->right->left = create_node(60);
	root->right->right = create_node(70);
	root->left->left->left = create_node(80);
	root->left->left->right = create_node(90);
	root->left->right->left = create_node(100);
	root->left->right->right = create_node(110);

	print_tree(root);
	printf("\n");

	lca = find_LCA(root,80,70);
	if(!lca) 
		printf("lca not available\n");
	else
		printf("LCA is %d\n",lca);

	delete_tree(root);

	return 0;
}
