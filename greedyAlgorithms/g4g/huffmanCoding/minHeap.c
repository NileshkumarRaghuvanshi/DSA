#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#include "minHeap.h"

struct heap *createHeap(int size) {

	struct heap *temp = malloc(sizeof(struct heap));
	if(temp) {
		temp->size = 0;
		temp->capacity = size;
		temp->arr = calloc(size,sizeof(struct heap_node));
		if(!temp->arr) {
			free(temp);
			return NULL;
		}
	}

	return temp;


}


void destroyHeap(struct heap *head) {

	if(head) {
		free(head->arr);
		free(head);
	}
}


void buildHeap(struct heap *head,struct heap_node *arr, int size) {

	

}

void swap(struct heap *head, int index1, int index2) {

	if(!head)
		return;

	int temp = head->arr[index1].data;
	head->arr[index1].data = head->arr[index2].data;
	head->arr[index2].data = temp;
}


void percolateDOWN(struct heap *head, int index) {

	if(!head || (index <1) || (index > head->size))
		return;

	if((index*2 +1) <= head->size) {
		printf("right children present\n");
		if(head->arr[index*2 +1 ].data <= head->arr[index*2].data) {
			printf("right child is smaller than left child\n");
			if(head->arr[index].data > head->arr[index*2 +1].data) {

				swap(head,index, index*2 +1);
				percolateDOWN(head,index*2 +1);
			}
		}
		else {
			printf("left child is smaller than right child\n");
			if(head->arr[index].data > head->arr[index*2].data) {

				swap(head,index, index*2);
				percolateDOWN(head,index*2);
			}
		}
	}
	else if((index*2 == head->size)) {

		if(head->arr[index].data > head->arr[index*2].data) {
			swap(head,index, index*2);
			percolateDOWN(head,index*2);
		}
	}




}

struct heap_node deleteMin(struct heap *head) {

	struct heap_node retval;
	if(!head || head->size <1)
		return retval;

	retval = head->arr[1];
	head->arr[1] = head->arr[head->size];
	head->size--;

	percolateDOWN(head,1);

	return retval;
	

}

void percolateUP(struct heap *head, int index) {

	if(!head || (index <=1))
		return;
	
	if(index > head->size)
		return;

	if(head->arr[index/2].data > head->arr[index].data) {
		swap(head,index/2, index);
		percolateUP(head,index/2);

	}
}

int insert(struct heap *head, struct heap_node *data) {


	if(!head || !data)
		return INT_MIN;
	
	if(head->size == head->capacity)
		return INT_MIN;

	
	if(head->size == 0) {
		(head->arr[++head->size]).data = data->data;
		(head->arr[head->size]).letter = data->letter;
		printf("inserting %d\n",data->data);
		(head->arr[head->size]).left = data->left;
		(head->arr[head->size]).right = data->right;
	}
	else {
		(head->arr[++head->size]).data = data->data;
		(head->arr[head->size]).letter = data->letter;
		printf("inserting %d\n",data->data);
		(head->arr[head->size]).left = data->left;
		(head->arr[head->size]).right = data->right;
		percolateUP(head,head->size);
	}

}

void printHeap(struct heap *head) {

	if(!head || (head->size < 1))
		return;

	int temp = 1;
	while(temp <= head->size) {
		printf("%d ",head->arr[temp].data);
		temp++;
	}
	printf("\n");

}
