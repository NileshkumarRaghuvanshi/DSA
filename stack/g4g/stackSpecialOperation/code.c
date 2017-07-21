#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack_data {

	int data;
	struct stack_ds *next;
};

struct stack_top {

	int top;
	struct stack_data *st;
};


struct stack_top *aux_stop = NULL;

struct stack_top * createStack() {


	struct stack_top *temp = malloc(sizeof(struct stack_top));
	if(!temp) {
		printf("error creating stack head\n");
		return NULL;
	}

	temp->st = (struct stack_data *)malloc(sizeof(struct stack_data)*MAX_SIZE);
	if(!temp->st) {
		printf("Error allocating memory to stack\n");
		temp->st = NULL;
	}
	temp->top = 0;
	return temp;
}

int topOfStack(struct stack_top *stop) {

	if(!isEmpty(stop))
		return ((stop->st[(stop->top) - 1]).data);
	else {
		printf("Stack is empty()\n");
		exit(-1);
	}
}

int isEmpty(struct stack_top *stop) {

	if(!stop->top)
		return 1;
	else
		return 0;

}

int isFull(struct stack_top *stop) {
	
	if(stop->top == MAX_SIZE)
		return 1;
	else
		return 0;
}


/*
struct stack_ds *createStackNode(int data) {

	struct stack_data *temp = NULL;
	temp = malloc(sizeof(struct stack_data));
	if(!temp) {
		printf("error creating stack node\n");
		return NULL;
	}

	temp->data = data;
	temp->next = NULL;

	return temp;

}
*/

void push(struct stack_top *stop, int data) {

	//struct stack_data *temp = NULL;
	if(!stop || !aux_stop) {
		printf("error adding the data to stack\n");
		return;
	}

	//temp = createStackNode(data);
	//if(temp) {
	if(!isFull(stop)) {
		printf("Data %d pushed\n",data);
		(stop->st[stop->top++]).data = data;
	}
	else {
		printf("No space left in stack\n");
		return;
	}
	
	if(!isEmpty(aux_stop)) {
		if(data < topOfStack(aux_stop)) {
			printf("found a new min\n");
			(aux_stop->st[aux_stop->top++]).data = data;
		}
	}
	else {
		//printf("Adding first element\n");
		aux_stop->st[aux_stop->top++].data = data;
	}
}

int pop(struct stack_top *stop) {

	if(!stop || !aux_stop) {
		printf("stack is not intialized\n");
		exit(-1);
	}

	if(topOfStack(stop) == topOfStack(aux_stop)) {
		printf("Min is extracted\n");
		aux_stop->top--;

	}

	return (stop->st[--stop->top]).data;
	
}


int getMin() {

	if(!isEmpty(aux_stop)) {
		//printf("returning top %d element\n",aux_stop->top);
		return (aux_stop->st[aux_stop->top-1]).data;
	}
}
int main() {


	struct stack_top *st = createStack();
	aux_stop = createStack();
	if(!st || !aux_stop) 
		return -1;

	push(st,15);
	push(st,10);
	push(st,3);
	push(st,4);
	push(st,5);
	push(st,2);
	push(st,7);
	push(st,11);
	push(st,9);

	printf("Min is %d\n",getMin());

	printf("poped %d\n",pop(st));
	printf("poped %d\n",pop(st));
	printf("poped %d\n",pop(st));
	printf("poped %d\n",pop(st));

	printf("Min is %d\n",getMin());


	return 0;
}
