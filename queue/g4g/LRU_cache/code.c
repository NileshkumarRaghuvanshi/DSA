#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


struct qNode {

	int pageNumber;
	struct qNode *next, *prev;
};

struct cacheQ {

	int totalCachePages;
	struct QNode *cache;
	struct qNode *front, *rear;
	int pageCount;
};


struct cacheHash {
	int capacity;
	struct qNode **list;
};



struct cacheHash *createCacheHash(int hashSize) {

	int i=0;
	struct cacheHash *temp = malloc(sizeof(struct cacheHash));
	if(!temp) {
		printf("ERROR : malloc cache Hash\n");
		exit(-1);
	}

	temp->capacity = hashSize;
	temp->list = (struct qNode **)malloc(sizeof(struct qNode *)*hashSize);
	//memset(*(temp->list),0,sizeof(*temp->list));
	for(i=0;i<hashSize;i++)
		temp->list[i] = 0;

	return temp;

}
struct cacheQ *createCache(int totalNoOfPages) {

	struct cacheQ *temp = malloc(sizeof(struct cacheQ));
	if(!temp) {
		printf("ERROR : malloc cacheQ\n");
		exit(-1);
	}

	temp->totalCachePages = totalNoOfPages;
	temp->front = temp->rear = NULL;
	temp->cache = NULL;
	temp->pageCount = 0;

	return temp;

}

struct qNode *createQNode(int pageNumber) {

	struct qNode *temp = malloc(sizeof(struct qNode));
	if(!temp) {
		printf("ERROR :  Malloc qNode \n");
		exit(-1);
	}

	temp->pageNumber = pageNumber;
	temp->prev = temp->next = NULL;

	return temp;

}


void enqueue(struct cacheQ *cache, struct cacheHash *hash, int pageNumber) {

	struct qNode *temp = createQNode(pageNumber);

	if(!temp) {
		printf("ERROR : Creating a new node\n");
		return;
	}

	if(isFull(cache)) {
		printf("cache is full\n");
		cache->rear = cache->rear->prev;
		free(cache->rear->next);
		cache->rear->next = NULL;

		temp->next = cache->front;
		cache->front->prev = temp;
		cache->front = temp;
	}
	else {
		printf("Cache is not full\n");
		if(cache->front) {
			temp->next = cache->front;
			cache->front->prev = temp;
			cache->front = temp;

		}
		else {
			printf("first element\n");
			cache->front = temp;
			cache->rear = temp;
		}

		++cache->pageCount;
	}


	hash->list[pageNumber] = temp;
}


void dequeue(struct cacheQ *cache, struct qNode *node) {


	struct qNode *temp = node->prev;

	if(temp) {

		if(node->next)
			temp->next = node->next;
		else 
			node->next->prev = temp;

		node->next = cache->front;
		cache->front->prev = node;
		cache->front = node;
	}

}



int isFull(struct cacheQ *cache) {

	return (cache->pageCount == cache->totalCachePages)? 1:0;
}

int isEmpty(struct cacheQ* cache) {

	return cache->pageCount?0:1;
}

void referencePage(struct cacheQ *cache, struct cacheHash *hash, int pageNumber) {


	if(hash->list[pageNumber] == NULL) {
		printf("page is not in the cache\n");
		enqueue(cache,hash,pageNumber);
	
	}
	else {
		printf("page is in the cache\n");

		
		struct qNode *temp = hash->list[pageNumber];

		dequeue(cache,temp);
	
	}

}


void printCache(struct cacheQ *cache) {

	struct qNode *temp = cache->front;
	while(temp) {

		printf("%d ",temp->pageNumber);
		temp = temp->next;
	}

	printf("\n");
}


int main() {

	struct cacheQ *cache 	= createCache(5);	
	struct cacheHash *hash 	= createCacheHash(10);
	referencePage(cache,hash,1);
	referencePage(cache,hash,2);
	referencePage(cache,hash,3);
	referencePage(cache,hash,4);
	referencePage(cache,hash,5);
	referencePage(cache,hash,6);
	referencePage(cache,hash,7);

	printCache(cache);
	referencePage(cache,hash,4);


	printCache(cache);
	return 0;
}
