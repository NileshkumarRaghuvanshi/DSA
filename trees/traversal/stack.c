#include <stdio.h>
#include <malloc.h>


struct stack_ds {
	int arr[100];
	int top;		
};

//int stack_arr[100];

struct stack_ds* create_stack() {
	struct stack_ds *temp = (struct stack_ds *)malloc(sizeof(struct stack_ds));
	temp->top = 0;
	return temp;
}

int top_of_stack(struct stack_ds *st) {

	return st->arr[(st->top -1)];
}
int is_stack_empty(struct stack_ds *st) {

	return st->top?0:1;
}

int is_stack_full(struct stack_ds *st) {

	return (st->top == 100)?1:0;	
}
void push(struct stack_ds *st,int data) {

	if(!is_stack_full(st)) {
		//printf("top @ %d\n",st->top);
		st->arr[st->top++] = data;
	}
	else
		printf("Error stack is FULL\n");
		

}

int pop(struct stack_ds *st) {

	if(!is_stack_empty(st)) {
		//printf("poped @ %d\n",(st->top-1));
		return st->arr[--st->top];
	}
	else
		printf("ERROR : stack is empty\n");

}
