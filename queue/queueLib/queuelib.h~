
/*
 * This is done to avoid waste of memeory,
 * Instead of having a single linked list to store data and pointer to next entry, where we waste unnecessary
 * memory for storing front and rear address, since they are going to be same for all the node in the queue
 * Hence it makes a lot of sense to seperate them out.
 * 
 * We use only the myQueue data structure and only this will be exposed to outside world.
 * A good library should act like a good servant, and a good servant listens to his master and amazes him,
 * through his capabilities, and not restricts him from doind something or not enforces some rules to do the thing 
 * master want
 */


struct myQueueList {
  long data;
  struct myQueueList *next;
};

struct myQueue {
  
  struct myQueueList *rear;
  struct myQueueList *front;
};

struct myQueue * createQueue();
int enQueue(struct myQueue **Q, long data);
int deQueue(struct myQueue **Q);
int frontElement(struct myQueue **Q);
int sizeQueue(struct myQueue **Q);
int isQueueEmpty(struct myQueue **Q);
void deleteQueue(struct myQueue **Q);
void printQueueMenu();