#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};


struct level_map {
	int level;
	int data;
	struct level_map *next;
};

void add_level (struct level_map **head,int data, int level) {

	printf("adding data %d to level %d\n",data,level);	

	if(!*head) 
		printf("adding a first node\n");

	struct level_map *temp = malloc(sizeof(struct level_map));
	if(!temp) {
		printf("error creating level map node\n");
		exit(-1);
	}

	temp->data = data;
	temp->level = level;
	temp->next = *head;
	*head = temp;
	
}

void print_inorder(struct tree_node *root) {

	if(root) {
		print_inorder(root->left);
		print_inorder(root->right);
		printf("%d ",root->data);
	}
}

struct tree_node* creat_node(int data) {
	printf("creating data\n");
	
	struct tree_node *temp =  (struct tree_node *)malloc(sizeof(struct tree_node));
	if(!temp) {
		printf("error creating a node\n");
		exit(-1);
	}

	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;


	return temp;
}

void get_level(struct tree_node *root, struct level_map **head, int level) {
	
	if(root) {

		add_level(head,root->data,level);
		get_level(root->left,head,level+1);	
		get_level(root->right,head,level-1);
	}
}

void get_max_min_level(struct level_map *head, int *max, int *min) {

	*max = 0;
	*min = 0;

	while(head) {

		if(head->level < *min)
			*min = head->level;
		if(head->level > *max)
			*max = head->level;

		head = head->next;

	}

	
}
void get_top_view(struct tree_node *root) {

	struct level_map *level_map_head = NULL;
	struct level_map *temp = NULL;
	int level_min, level_max;

	get_level(root,&level_map_head,0);

	get_max_min_level(level_map_head,&level_max,&level_min);

	printf("max = %d, min =%d\n",level_max, level_min);

	int level = level_min;
	while(1) {
		
		temp = level_map_head;
		printf("checking for level = %d\n",level);
		while(temp) {
			if(temp->level == level) {
				printf("level = %d data = %d\n",temp->level,temp->data);
			}

			temp = temp->next;
		}

		if(level == level_max)
			return;
		level++;

	}

}
int main() {

	struct tree_node *root = NULL;
	root = creat_node(1);
	root->left = creat_node(2);
	root->right = creat_node(3);
	root->left->left = creat_node(4);
	root->left->right = creat_node(5);
	root->right->left = creat_node(6);
	root->right->right = creat_node(7);

	root->left->right->right = creat_node(9);
	root->left->right->left = creat_node(8);
	root->left->right->right->right = creat_node(10);
	root->left->right->right->right->right = creat_node(11);


	print_inorder(root);

	printf("\n");


	get_top_view(root);
	return 0;
}
