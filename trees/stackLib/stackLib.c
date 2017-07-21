#include "stackLib.h"
#include <stdlib.h>
#include <stdio.h>

struct myStack *top[5] = {0};
unsigned int stackIndex = 0;

struct myStack** createStack() {

    return &top[stackIndex++];
}
int pushToStack(struct myStack **stackptr, long data) {
  
  struct myStack *temp = NULL;
  temp = malloc(sizeof(struct myStack));
  if(!temp) {
    printf("Error allocating memory to stack element\n");
    return -1;
  }
  temp->data = data;
  temp->next = 0;

  temp->next = *stackptr;
  *stackptr = temp;
  //printf("Data pushed %ld\n",(*stackptr)->data);
  //printf("top add = %x\n",stackptr);
  
  return 0;
}
long popFromStack(struct myStack **stackptr) {
  
  struct myStack *temp = *stackptr;
  if(!isStackEmpty(stackptr)) {
    long data = temp->data;
    *stackptr = (*stackptr)->next;
    free(temp);
    //printf("data popped = %ld\n",data);
    return data;
  }
  else {
    printf("EXCEPTION : stack is empty!!!\n");
    return -1;
  }

  //printf("top add = %x\n",stackptr);
}

long topOfStack(struct myStack **stackptr) {
  
  if(!isStackEmpty(stackptr))
    return ((*stackptr)->data);
  else
    return -1;
}

int isStackEmpty(struct myStack **stackptr) {
  
 return (*stackptr?0:1); 
}

void deleteStack(struct myStack **stackptr) {
  
  while(*stackptr) {
    struct myStack *temp = *stackptr;
    printf("Deleting = %l\n",temp->data);
    *stackptr = (*stackptr)->next;
    free(temp);
  }
}


int sizeOfStack(struct myStack **stackptr) {
  struct myStack *temp = *stackptr;
  unsigned int len = 0;
  while(temp) {
    temp = temp->next;
    len++;
  }
  
  return len;
}
