#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node {
	int data;
	struct node *next;
};


struct node *createNode(int data) {

	struct node *temp = malloc(sizeof(struct node));
	if(temp) {
		temp->data =data;
		temp->next = NULL;
	}
	else {
		printf("Malloc error\n");
		exit(-1);
	}

	return temp;
}



void printList(struct node *head) {


	while(head) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

struct node *reverseList(struct node **head, struct node *node) {

	struct node *temp;
	if(!node->next) {

		*head = node;
		return node;
	}
		

	temp = reverseList(head,node->next);

	temp->next = node;
	node->next = NULL;
	return node;
}


int main() {

	struct node *root = createNode(10);
	//root->next = createNode(20);
	//root->next->next = createNode(30);
	//root->next->next->next = createNode(40);
	//root->next->next->next->next = createNode(50);
	//root->next->next->next->next->next = createNode(60);


	
	printList(root);
	reverseList(&root,root);
	printList(root);
	reverseList(&root,root);
	printList(root);
	return 0;
}
