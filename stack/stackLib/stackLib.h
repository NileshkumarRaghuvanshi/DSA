
struct myStack  {
  long data;
  struct myStack *next;
};
struct myStack** createStack();
int pushToStack(struct myStack **stackptr, long data);
long popFromStack(struct myStack **stackptr);
long topOfStack(struct myStack **stackptr);
int isStackEmpty(struct myStack **stackptr);
void deleteStack(struct myStack **stackptr);
int sizeOfStack(struct myStack **stackptr);
