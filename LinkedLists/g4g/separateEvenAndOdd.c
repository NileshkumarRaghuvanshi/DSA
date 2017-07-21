#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct  node {
	int data;
	struct node *left;
};

struct node * createNode(int data) {
	
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp) {
		temp->data = data;
		temp->left = NULL;
	}
	else {
		printf("ERROR : malloc\n");
		exit(-1);
	}

	return temp;
}

void printList(struct node *head) {

	struct node *temp = head;
	while(temp) {
		printf("%d ",temp->data);
		temp = temp->left;
	}
	printf("\n");
}


void separateEvenOdd(struct node *head) {

	struct node *evenptr = head;
	struct node *oddptr = head;
	struct node *temp = head;

	while(evenptr && oddptr) {

		while((evenptr->data%2) == 0) {


			evenptr = evenptr->left;
			if(!evenptr)
				break;

		}

		while((oddptr->data)%2 != 0) {

			oddptr = oddptr->left;
			if(!oddptr)
				break;
		}

		if(evenptr && oddptr) {
			int temp = evenptr->data;
			evenptr->data = oddptr->data;
			oddptr->data = temp;
		}

		printList(head);

	}

}





/*
void separateEvenOdd(struct node *head) {

		struct node *evenptr = NULL;
		struct node *oddptr = NULL;
		struct node **currptr = &head;


		if(!head)
			return;
	
		while(*currptr) {

			if(((*currptr)->data)%2 == 0) {

				if(evenptr) {
					struct node *temp = *currptr;
					struct node *temp1 = evenptr->left;
					(*currptr) = (*currptr)->left;
					evenptr->left = temp;
					evenptr->left->left = temp1;
					evenptr = evenptr->left;
				}
				else
					evenptr = *currptr;

			}
			else {

				if(oddptr) {
					struct node *temp = *currptr;
					struct node *temp1 = oddptr->left;
					(*currptr) = (*currptr)->left;
					oddptr->left = temp;
					oddptr->left->left = temp1;
				}
				else
					oddptr = *currptr;
			}

			*currptr = (*currptr)->left;
			printList(head);
		}


}

*/
int main() {



	struct node *head = createNode(-1);
	head->left = createNode(1101);
	head->left->left = createNode(101);
	head->left->left->left = createNode(21);
	head->left->left->left->left = createNode(301);
	head->left->left->left->left->left = createNode(501);
	head->left->left->left->left->left->left = createNode(41);


	printList(head->left);
	separateEvenOdd(head->left);
	return 0;
}
