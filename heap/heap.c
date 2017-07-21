#include <stdio.h>
#include <malloc.h>
#include "heap.h"


typedef struct heapRoot {
	DATA *heapArray;//pointer to array of elements
	int capacity;	//Max capacity of element Heap can store
	int size;	//Current size of Heap
} heapRoot;

int getSize(struct heapRoot *h) {

	return (h?h->size:0);
}
DATA getiElement(struct heapRoot *h, int index) {
	return h?h->heapArray[index]:-1;
}
struct heapRoot * createHeap(int MaxHeap) {
	if(MaxHeap) {
		printf("HEAP : Creating Max heap!!!\n");
		#define MAXHEAP
	}
	else {
		printf ("HEAP : Creating Min Heap!!!\n");

	}
	DATA *tempArray = malloc(sizeof(DATA)*MAX_HEAP_SIZE);
	if(!tempArray) {
		printf("HEAP : Error creating heap!!!\n");
		return NULL;
	}

	struct heapRoot *tempHeapPtr = malloc(sizeof(struct heapRoot));
	
	if(tempHeapPtr) {
		tempHeapPtr->heapArray = tempArray;
		tempHeapPtr->capacity = MAX_HEAP_SIZE;
		tempHeapPtr->size = 0;
	}
	else
		printf("HEAP : Error creating heapRoot\n");

	return tempHeapPtr;
}

void destroyHeap(struct heapRoot *h) {
	printf("HEAP : destroying Heap!!!\n");
	free(h->heapArray);
	free(h);
	h = NULL;
}

void swapValues(struct heapRoot *h,int indexa, int indexb) {
	DATA temp = h->heapArray[indexb];
	h->heapArray[indexb] = h->heapArray[indexa];
	h->heapArray[indexa] = temp;
}

void percolateUP(struct heapRoot *h, int size) {
	printf("percolateUP : size = %d\n",size);
	if((size) > 1) {
		if(h->heapArray[size/2] > h->heapArray[size]) { 	//parent > child
			printf("parent = %d is bigger than child = %d \n",h->heapArray[(size/2)],h->heapArray[size]);
			swapValues(h,(size/2),size);		//swap parent with child
			percolateUP(h,size/2);			//check the new parent to maintain heap order
		}
	}
}

int insertHeap(struct heapRoot *h, DATA data) {
	
	printf("HEAP : Inserting node!!!\n");
	
	if(h->size != h->capacity) {
		h->heapArray[++(h->size)] = data;
		percolateUP(h,h->size);
	}
	else {
		printf("Heap is full\n");
		return 0;
	}

}

//Need to make sure if the parent has one child or two child
//Need to avoid comparing with junk values
/****************************************************************************
**Multiple implementation are possible. one of them would be
**
**
*/
void percolateDOWN(struct heapRoot *h, int index) {

	if((index*2+1) <= h->size) {
		if(h->heapArray[index*2] <= h->heapArray[index*2 + 1]) {
			if(h->heapArray[index] > h->heapArray[index*2]) {
			//	printf("parent = %d is greter than left child = %d\n",h->heapArray[index],h->heapArray[index*2]);
				swapValues(h,index,(index*2));
				percolateDOWN(h,index*2);
			}
			else
				printf("parent and left are equal\n");
		}
		else if (h->heapArray[index*2] >=  h->heapArray[index*2 + 1]){
			if(h->heapArray[index] > h->heapArray[index*2 + 1]) {
				//printf("parent = %d is greter than right child = %d\n",h->heapArray[index],h->heapArray[index*2 + 1]);
				swapValues(h,index,(index*2 + 1));
				percolateDOWN(h,(index*2 +1));
			}
			else
				printf("parent and right are equal\n");
		}
		else
			printf("something really weird!!!\n");
	}
	else if((index*2)  == h->size) {
		if(h->heapArray[index] > h->heapArray[index*2]) {
			//printf("parent is bigger than its only left child\n");
			swapValues(h,index,(index*2));
			percolateDOWN(h,(index*2));
		}
		//else
			//printf("nothing to do!!!\n");
	}
	//else
		//printf("No child to look further parent index = %d!!!\n",index);
}

//Need to alocate the last value of the heap array and
//then run the percolateDOWN function to bring it down
//proper place
DATA removeHeap(struct heapRoot *h) {

	DATA ret;
	//printf("removing a Min elememt from heap\n");
	if(h->size > 0) {
		ret = h->heapArray[1];
		h->heapArray[1] = h->heapArray[h->size];
		h->size--;

		percolateDOWN(h,1);
	}
	else {
		printf("No data in the heap\n");
		ret = -1;
	}

	printf("ret = %d\n",ret);
	return ret;
}

void buildHeap(struct heapRoot *h, DATA *arrayPtr, int noOfElement) {
	
	int i;
	printf("HEAP : buildig heap from array\n");
	//h = createHeap(0);
	for(i=0;i<noOfElement;i++)
		h->heapArray[i + 1] = arrayPtr[i];

	h->size = noOfElement;
	for (i=(noOfElement/2); i>0; i--) {
		printf("Checking parent %d\n",h->heapArray[i]);
		percolateDOWN(h,i);
	}

}

DATA GetRoot(struct heapRoot *h) {

}

