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
		print_tree(root->right);
		printf("%d ",root->data);
	}
}



void preorder (struct treeNode *root) {

	if(root) {
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void preorder_wo_recursion(struct treeNode *root) {

	struct stack_ds *st = create_stack();
	if(root) {
		//push(st,root);
		while(1) {
			
			if(root) {
				push(st,root);
				printf("%d ",((struct treeNode *)top_of_stack(st))->data);
				root = root->left;

			}
			else {
			

				if(!((struct treeNode *)top_of_stack(st))->right) {
					//printf("leaf node\n");
					pop(st);
				}
				//else
					//root = ((struct treeNode *)pop(st))->right;


				if(is_stack_empty(st)) {
					//printf("stack is empty\n");
					return;
				}
				else
					root = ((struct treeNode *)pop(st))->right;

			}

		}

	}






}

void post_order_wo_recursion (struct treeNode *root) {

	printf("here\n");
	struct stack_ds* st = create_stack();
	if(root) {
		//push(st,root);
		printf("root is pushed\n");
		while(1/*!is_stack_empty(st)*/) {

			printf("stack is not empty\n");

			if(root) {
				push(st,root);
				printf("pushing %d\n",root->data);
				root = root->left;
				printf("going left\n");
			}
			else {

				if(is_stack_empty(st)) {
					printf("stack is empty\n");
					return;
				}
				else {

					if(!(((struct treeNode *)top_of_stack(st))->right)) {
						printf("this is a leaf Node\n");
						root = pop(st);
						printf("%d ",root->data);
						
						if(is_stack_empty(st)) {
							printf("stack is empty\n");
							return;
						}
						else {					
							if(root->data == ((struct treeNode *)top_of_stack(st))->right->data) {
								printf("coming from right\n");
								root = pop(st);
								printf("%d ",root->data);
								//printf("going right if\n");
								//root = (((struct treeNode *)top_of_stack(st))->right);
							}
						}
					}		
					printf("going right else\n");
					root = (((struct treeNode *)top_of_stack(st))->right);
				}
			}
		}
	}
}


int find_path(struct treeNode *root, int sum) {

	int found = 0;
	if(root) {
		sum-= root->data;
		if(sum == 0) {
			//printf("sum is zero\n");
			printf("%d ", root->data);
			found = 1;
			return found;
		}
		if(!found) {
			//printf("sum before %d\n",sum);

			found = find_path(root->left,sum);
			if(!found)
				found = find_path(root->right,sum);
			//return (find_path(root->left,sum) || find_path(root->right,sum));
		}
	

		if(!found) {
			sum+= root->data;
			//printf("sum after %d\n",sum);
		}
		else
			printf("%d ",root->data);



	}

	return found;
}

int main() {

	struct treeNode *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	root->left->right = create_node(50);
	root->right->left = create_node(60);
	root->right->right = create_node(70);
	root->left->left->right = create_node(80);
#if 0
	printf("Post order traversal\n");
	print_tree(root);
	printf("\n");
	post_order_wo_recursion(root);
	printf("\n");
#endif

#if 0
	printf("in order traversal\n");
	preorder(root);
	printf("\n");
	printf("inorder wo recursion\n");
	preorder_wo_recursion(root);
	printf("\n");
#endif

#if 1
	printf("finding from to root to any of the nodes\n");
	if(!find_path(root,10))
		printf("path not found");
	printf("\n");

#endif
	delete_tree(root);

	return 0;
}
