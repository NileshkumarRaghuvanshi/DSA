#ifndef STACK_H
#define STACK_H

typedef struct stack *stackPtr;

stackPtr createStack();
void destroyStack();

int push(stackPtr st, int data);
int pop(stackPtr st);

int isStackEmpty(stackPtr st);
int isStackFull(stackPtr st);

#endif
