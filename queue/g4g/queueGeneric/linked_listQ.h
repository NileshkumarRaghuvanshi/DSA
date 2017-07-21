#ifndef LINKED_LISTQ
#define LINKED_LISTQ

typedef long long int  DATA;

struct queue_node {
	DATA data;
	struct queue_node *next;
};

struct queue_head {

	struct queue_node *front;
	struct queue_node *rear;
};



struct queue_node *createQNode(DATA data);
struct queue_head * createQ();
void deleteQ(struct queue_head *q) ;
void enqueue(struct queue_head *q, DATA data);
DATA dequeue(struct queue_head *q);
DATA front(struct queue_head *q); 
DATA rear(struct queue_head *q);
int isEmpty(struct queue_head *q);

#endif
