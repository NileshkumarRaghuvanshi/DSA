#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct mylist_node {
	int data;
	struct mylist_node *next;
};


struct mylist {	
	struct mylist_node *node;
};


struct mylist_node * create_node(int data) {

	struct mylist_node *temp = (struct mylist_node *)malloc(sizeof(struct mylist_node));
	if(!temp) {
		printf("ERROR :  creating a node\n");
		return 0;
	}

	temp->data = data;
	temp->next = NULL;

	return temp;
}

int push(struct mylist **head, int data) {

	printf("pushing %d\n",data);

	if(!*head) {
		printf("head is NULL\n");
		return 0;
	}

	struct mylist_node **handle = &((*head)->node);
	if(!*handle)
		printf("inserting first element\n");
	while(*handle) {
		printf("inserting after %d\n",(*handle)->data);
		handle = &((*handle)->next);
	}

	*handle = create_node(data);

	if(!*handle) {
		printf("ERROR : could not insert a node\n");
		return 0;
	}
	
	printf("returning\n");			
	return 1;
}

void print_list(struct mylist *head) {

	if(head) {
		struct mylist_node *handle = head->node;
		while(handle) {
			printf("%d ",handle->data);
			handle = handle->next;
		}
	}
	else
		printf("list is empty\n");

	printf("\n");
}

struct mylist *create_list_head() {

	return calloc(1,sizeof(struct mylist));	
}
int main() {
	
	struct mylist *head = create_list_head();
	head->node = NULL;

	assert(push(&head,10));
	assert(push(&head,20));
	assert(push(&head,30));
	assert(push(&head,40));
	assert(push(&head,50));
	assert(push(&head,60));

	print_list(head);

	return 0;
}
