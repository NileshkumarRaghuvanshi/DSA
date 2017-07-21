#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
} *head = NULL;


void push (struct node **head_ptr, int data) {

	//printf("pushing %d\n",data);
	struct node *temp = malloc(sizeof(struct node));
	if(!temp) {
		printf("error allocating node\n");
		exit(-1);
	}
	temp->data = data;
	temp->next = NULL;

	struct node **new_node = head_ptr;
	while(*new_node) {
		new_node = &((*new_node)->next);
	}
	
	(*new_node) = temp;

}

void print_list(struct node *head_ptr) {

	while(head_ptr) {
		printf("%d ",head_ptr->data);
		head_ptr = head_ptr->next;
	}

}

void print_reverse(struct node* head_ptr) {

	if(!head_ptr)
		return;
	print_reverse(head_ptr->next);
	printf("%d ",head_ptr->data);

}

void reverse_list(struct node **head_ptr) {

	struct node *prev = NULL;
	struct node *current = *head_ptr;
	struct node *next = NULL;

	while(current) {

		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}


	*head_ptr = prev;
}


void delete_recursive(struct node * head_ptr) {

	if(!head_ptr)
		return;
	delete_recursive(head_ptr->next);
	printf("freeing = %d\n",head_ptr->data);
	free(head_ptr);
}

int main() {

	push(&head,10);
        push(&head,20);
        push(&head,30);
        push(&head,40);
        push(&head,50);
        push(&head,60);

	print_list(head);
	printf("\n");
	print_reverse(head);
	printf("\n");


	printf("reversing linked list\n");
	reverse_list(&head);

	printf("print new list\n");
	print_list(head);
	printf("\n");
	delete_recursive(head);
	return 0;
}
