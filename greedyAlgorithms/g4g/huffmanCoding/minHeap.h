#ifndef MINHEAP_H
#define MINHEAP_H
struct heap_node {

	int data;
	char letter;
	struct heap_node *left;
	struct heap_node *right;
};


struct heap {

	struct heap_node *arr;
	int size;
	int capacity;
};


struct heap *createHeap(int size);
void destroyHeap(struct heap *head);
void buildHeap(struct heap *head,struct heap_node *arr, int size);
struct heap_node deleteMin(struct heap *head);
void swap(struct heap *head, int index1, int index2);
void percolateUP(struct heap *head, int index);
int insert(struct heap *head, struct heap_node *data);
void printHeap(struct heap *head);

#endif //MINHEAP_H
