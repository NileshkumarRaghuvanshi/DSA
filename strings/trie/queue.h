#ifndef QUEUE_H
#define QUEUE_H

typedef char element;
typedef struct queue *qRoot;

qRoot createQ();
void destroyQ(qRoot root);

int addQ(element val);
element removeQ();

void printQ();
void removeFromBack();

#endif
