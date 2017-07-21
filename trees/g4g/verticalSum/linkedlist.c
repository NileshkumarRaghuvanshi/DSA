#include <stdio.h>
#include <malloc.h>

struct linked_list_node {

	int data;
	struct linked_list_node *next;
	struct linked_list_node *prev;
};

struct linked_list_ds {
	struct linked_list_node *head;
};


int _addNode(linked_list_node **head, int data ) {

	
	struct linked_list_node *temp =  malloc(sizeof(struct linked_list_node));
	if(temp) {
		temp->data = data;
		temp->next = temp->prev = NULL;
		head = temp;
		return 1;
	}

	return 0;

}
int addNode(linked_list **ll, int data) {


	if(!ll)
		return NULL;
	else
		return _addNode(&((*ll)->head),data);

}

linked_list *createLinkedList() {


	struct linked_list_ds *temp = malloc(sizeof(struct linked_list_ds));
	if(temp) {
		temp->head = NULL;
	}

	return temp;

}

void deleteLinkedList(linked_list *ll) {

	if(!ll)
		return;

	struct linked_list_node *temp = ll->head;
	struct linked_list_node *temp1 = NULL;
	while(temp) {
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
		
	

}
