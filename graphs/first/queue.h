#ifndef QUEUE_H
#define QUEUE_H


typedef struct Q * Qptr;

Qptr createQ();
void destroyQ();

int isEmpty(Qptr Q);

int nQ(Qptr q, int data);
int dQ(Qptr q);



#endif
