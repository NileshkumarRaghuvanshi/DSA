#ifndef LINKED_LISTQ
#define LINKED_LISTQ

struct queue_node {
	int data;
	struct queue_node *next;
};

struct queue_head {

	struct queue_node *front;
	struct queue_node *rear;
};



struct queue_node *createQNode(int data);
struct queue_head * createQ();
void deleteQ(struct queue_head *q) ;
void enqueue(struct queue_head *q, int data);
int dequeue(struct queue_head *q);
int front(struct queue_head *q); 
int rear(struct queue_head *q);
int isEmpty(struct queue_head *q);
	
#endif
