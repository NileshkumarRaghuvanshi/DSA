#include "stack.h"
#include "malloc.h"


#define MAX_STACK_SIZE 100

struct stack {
	int data[MAX_STACK_SIZE];
	int top;
};

stackPtr createStack() {

	return (stackPtr )calloc(1,sizeof(struct stack));
}

void destroyStack(stackPtr st) {
	free(st);
}

int isStackFull(stackPtr st) {
	return (st->top == MAX_STACK_SIZE)? 1: 0;
}

int isStackEmpty(stackPtr st) {
	return (st->top == 0)? 1 : 0;
}

int push(stackPtr st, int data) {
	
	if(isStackFull(st))
		return -1;
	
	st->data[(st->top++)] = data;

	return 0;
}

int pop(stackPtr st) {

	if(isStackEmpty(st))
		return -1;

	return st->data[--(st->top)];
}		
