#include "trie.h"
#include "queue.h"

#include <stdio.h>
#include <malloc.h>

struct trieNode {
	char data;
	val value;
	struct trieNode *next;
	struct trieNode *sib;
};

struct trieNode* createNode() {
	struct trieNode *temp = malloc(sizeof(struct trieNode));
	if(!temp) 
		printf("ERROR : creating node!!!\n");

	return temp;

}


trieRoot createTrie() {
	printf("Creating trie Node\n");
	createQ();	
	trieRoot tempRoot = malloc(sizeof(struct trieNode));
	if(!tempRoot) {
		printf("ERROR creating root Node!!!\n");
		return 0;
	}
	
	tempRoot->data = -1;
	tempRoot->value = -1;
	tempRoot->next = NULL;
	tempRoot->sib = NULL;
	
	return tempRoot;
}

void destroyTrie(trieRoot root) {

	printf("Deleting trie node\n");
	free(root);
}

int trieAdd(trieRoot *root, char *key, val value) {
	
	int ret = 0;
	unsigned int ind = 0;	
	printf("Adding key %s and value =%d to DB\n",key,value);

	trieRoot *temp = &((*root)->sib);
	while (1) {
		while(*temp) {
			if((*temp)->data != key[ind]) {
				printf("No matching sib with key char=%c trie char=%c\n",key[ind],(*temp)->data);
				printf("Checking for new LEVEL\n");
				temp = &((*temp)->next);
			}
			else {
				printf("found matching sib %c\n",key[ind]);
				temp = &((*temp)->sib);
				ind++;
			}
		}

		trieRoot node = malloc(sizeof(struct trieNode));
		if(node) {
			printf("creating a new node with char= %c\n", key[ind]);
			node->data = key[ind];
			node->value = -1;
			node->sib = node->next = 0;	

			*temp = node;
		}
		else {
			printf("ERROR : creating nodes!\n");
			ret =0;
			break;
		}

		if(!key[ind]) {
			(*temp)->value = value;
			ret = 1;
			printf("Key = added successfully\n");
			break;
		}
		else {
			temp = &((*temp)->sib);
			ind++;
		}
	}

	return ret;
}

void triePrint(trieRoot root) {
	printf("printing trie\n");
	//while(root);
}

int skip = 0;
void _trieRemove(trieRoot *root, char *key) {

	if(!*root) {
		if(!key[0])
			skip =0;
		return;
	}

	if((*root)->data != key[0]) {
		printf("No match @ trie char =%c key char = %c\n",(*root)->data,key[0]);
		_trieRemove(&((*root)->next),key);
		printf("next @ char =%c\n",(*root)->data);
		skip =1;
	}
	else {
		printf("match @ char = %c\n",key[0]);
		_trieRemove(&((*root)->sib),&key[1]);
		if(!((*root)->next) && !skip) {
			printf("removing char=%c\n",(*root)->data);
			free(*root);
			skip = 0;
		}
		else if (((*root)->next) && !skip ) {
			printf("next present at char = %c\n",(*root)->data);
			trieRoot temp = (*root);
			*root = (*root)->next;
			free(temp);
			skip =1;
		}
		
	}
}


void trieRemove(trieRoot root, char *key) {
	_trieRemove(&(root->sib), key);
}
/*
void trieRemove(trieRoot root, char *key) {
	
	int ret = 0;
	int ind = 0;
	printf("removing key = %s \n",key);
	trieRoot start = 0;
	trieRoot temp = root->sib;
	start = temp;

	while(key[ind]) {
		if(temp->data == key[ind]) {
			if(temp->next) {
				start = temp->sib;
				printf("Some string on the same level\n");
			}
			printf("match @ %c\n",temp->data);
			temp = temp->sib;
			ind++;
		}
		else {
			temp = temp->next;
			printf("Going to next level\n");
			start = temp;
		}
	}

	printf("start char= %c\n",start->data);

	do {
		trieRoot temp = start;
		start = start->sib;
		printf("removing char %c\n",temp->data);
;		free(temp);
	} while(start);
}

*/

val trieGetValue(trieRoot root, char *key) {
	val value = -1;
	unsigned int ind = 0;
	printf("finding the value for the key = %s\n",key);
	trieRoot temp = root->sib;

	while(temp) {

		if(temp->data != key[ind]) {
			printf("No match trie key char = %c key char = %c\n",temp->data,key[ind]);
			temp = temp->next;
		}
		else {
			if(!key[ind]) {
				printf("match\n");
				value = temp->value;
				break;
			}
			printf("match @ sib = %c\n",temp->data);
			ind++;
			temp = temp->sib;
		}
	}
	return value;
}

void _trieKeyWithMatchingPrefix(trieRoot root, char *key,int found) {

	if(!root)
		return;

	if(!found) {
		if(key[0]) {
			if(root->data != key[0]) {
				printf("No match, key char = %c, trie char = %c\n",key[0],root->data);
				_trieKeyWithMatchingPrefix(root->next,&key[0],0);
			}
			else {
				printf("adding %c\n",root->data);
				addQ(root->data);
				_trieKeyWithMatchingPrefix(root->sib,&key[1],0);
				removeFromBack();
			}
		}
		else {
			printf("Key is present\n");
			found = 1;
			_trieKeyWithMatchingPrefix(root,0,1);
		}
	}
	else {
		if(!root->data) {
			printQ();
			return;
		}
		_trieKeyWithMatchingPrefix(root->next,0,1);
		addQ(root->data);
		_trieKeyWithMatchingPrefix(root->sib,0,1);
		removeFromBack();
		
	}


}

void trieKeyWithMatchingPrefix(trieRoot root, char *prefix) {

        printf("Checking all the keys with matching %s prefix\n",prefix);
        _trieKeyWithMatchingPrefix(root->sib,prefix,0);
}

void _triePrintKeys(trieRoot root) {

	if(!root) //if node is null
		return;

	if(!root->data) {//if node has null char
		printQ();
		return;
	}

	_triePrintKeys(root->next);
	addQ(root->data);
	_triePrintKeys(root->sib);
	removeFromBack();

}

void triePrintKeys(trieRoot root) {
	printf("printing keys internal\n");
	_triePrintKeys(root->sib);
}

int trieIsMember(trieRoot root, char *key) {

	int ret =0;
	unsigned int ind = 0;
	printf("checking if key =%s is present\n",key);
	
	trieRoot temp = root->sib;
	while(temp) {
		if(temp->data != key[ind]) {
			printf("Checking a new LEVEL\n");
			temp = temp->next;
		}
		else {
			printf("Found a match: char = %c\n", key[ind]);
			
			if(!key[ind]) {
				ret =1;
				printf("Key is present\n");
				break;
			}

			ind++;
			temp = temp->sib;
		}
	}

	return ret;
}
