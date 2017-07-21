//Input : 
//Array of letters with their frequencies


//DS
//we need a min heap to get the least two frequencies
//Tree: to store the letters at the leaf node.

//Algorithm
//

//output:
//print binary code for all the letters



#include <stdio.h>
#include <malloc.h>

#include "minHeap.h"


//struct huffmanTreeNode {
//	struct heap_node *node;
//};

struct huffmanTreeRoot {

	struct heap_node *root;

};


struct heap_node *createHuffmanNode(struct heap_node node) {

	struct heap_node *temp = malloc(sizeof(struct heap_node));
	if(temp) {
		temp->data = node.data;
		temp->letter = node.letter;
		temp->left = node.left;
		temp->right = node.right;
	}
	return temp;
}


struct huffmanTreeRoot *createHuffmanTree() {

	struct huffmanTreeRoot *temp = malloc(sizeof(struct huffmanTreeRoot));
	if(temp) {
		temp->root = NULL;
	}

	return temp;
}

void printTree(struct heap_node *root) {

	if(!root)
		return;

	if(!root->left && !root->right){
		printf("%d ", root->data);
		return;
	}

	if(!root->left || !root->right) {
		//printf("problem\n");
		if(root->left)
			printf("%d ",root->data);
		if(root->right)
			printf("%d ",root->data);

		return;
	}
	
	printTree(root->left);
	printTree(root->right);
}


struct heap_node *huffmanEncoding(struct heap *heap_root) {

	struct heap_node temp;
	struct heap_node *huffmanLeftNode;
	struct heap_node *huffmanRightNode;
	struct heap_node *huffmanParent;
	temp = deleteMin(heap_root);
	printf("1st min is %d\n",temp.data);
	huffmanLeftNode = createHuffmanNode(temp);
	
	if(heap_root->size == 0) {
		printTree(huffmanLeftNode);
		return huffmanLeftNode;
	}

	temp = deleteMin(heap_root);
	printf("2nd min is %d\n",temp.data);
	huffmanRightNode = createHuffmanNode(temp);

	huffmanParent = createHuffmanNode(temp);
	huffmanParent->left = huffmanLeftNode;//createHuffmanNode(deleteMin(heap_root));
	huffmanParent->right = huffmanRightNode;//createHuffmanNode(deleteMin(heap_root));
	huffmanParent->data = ((huffmanParent->left)->data) + ((huffmanParent->right)->data);
	huffmanParent->letter = 0xff;
	
	printTree(huffmanParent);
	insert(heap_root,huffmanParent);
	huffmanEncoding(heap_root);
}


int main() {

	struct heap *root = createHeap(15);
	struct heap_node temp;
	struct heap_node *res;
	
	temp.data = 15;
	temp.letter = 'a';	
	insert(root,&temp);
	
	temp.data = 18;
	temp.letter = 'b';
	insert(root,&temp);
	
	temp.data = 20;
	temp.letter = 'c';
	insert(root,&temp);
	
	temp.data = 1;
	temp.letter = 'z';
	insert(root,&temp);


	temp.data = 2;
	temp.letter = 'y';
	insert(root,&temp);

	temp.data = 3;
	temp.letter = 'x';
	insert(root,&temp);
	printHeap(root);


	temp = deleteMin(root);
	printf("minum is %d \n",temp.data);

	printHeap(root);


	struct huffmanTreeRoot *tree = createHuffmanTree();

	tree->root = huffmanEncoding(root);
	//printTree(tree->root);


	return 0;
}
