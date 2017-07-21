#include <stdio.h>
#include <malloc.h>

struct linked_list {

	int data;
	struct linked_list *next;
};

struct linked_list* createNode(int data) {

	struct linked_list *temp = malloc(sizeof(struct linked_list));
	if(temp) {
		temp->data = data;
		temp->next = NULL;
		return temp;
	}

	return NULL;
}


void print_list(struct linked_list *head) {

	if(head) {

		printf("%d ",head->data);
		print_list(head->next);
	}

}

struct linked_list* findLoop(struct linked_list *head) {


	struct linked_list *slowptr = head;
	struct linked_list *fastptr = head;
	
	//handle the one element  case without loop
	if(!head->next)
		return NULL;

	//handle more than one element case with or without loop
	slowptr = head->next;
	fastptr = head->next->next;
	while(fastptr) {

		if(fastptr == slowptr) {
			printf("found loop\n");
			return fastptr;
		}

		printf("%d , %d\n",slowptr->data, fastptr->data);
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;

	}

	return NULL;
	
}


void findOrigin(struct linked_list *head) {


	struct linked_list *startptr = head;
	struct linked_list *meetptr =  NULL;

	//handle empty list
	if(!head)
		return;

	meetptr = findLoop(head);
	if(!meetptr) {
		printf("No loop in the linkedList\n");
		return ;
	}

	//if we start from the head and from the meeting point one place at a time
	//then we can reach the start of the loop, I have given the proof in the doc file
	while(startptr != meetptr) {
		startptr = startptr->next;
		meetptr = meetptr->next;
	}

	printf("origin is %d\n",startptr->data);

}


int main() {


	struct linked_list *head;
/*
	10->20->30->40->50->60->
		^	       |
		|	       |
		---------------

*/	
	head = createNode(10);
	head->next = createNode(20);
	//head->next = head;
	head->next->next = createNode(30);
	head->next->next->next = createNode(40);
	head->next->next->next->next = createNode(50);
	head->next->next->next->next->next = createNode(60);

	head->next->next->next->next->next->next = head->next->next;

	findOrigin(head);
	//print_list(head);
	//printf("\n");
	return 0;
}
