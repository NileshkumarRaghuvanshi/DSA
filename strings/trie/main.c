#include <stdio.h>
#include "trie.h"



int main() {


	printf("trie DS!!!\n");
	trieRoot root = createTrie();
	if(!root)
		printf("Error creating the trie root\n");

	int choice = 0;
        do {

                printf("Hello Welcome to trie programm!!!\n \
                        please select any one of these option:\n \
                        1.  Insert a key.\n \
                        2.  Remove a key.\n \
                        3.  Search a key.\n \
                        4.  Print trie\n \
                        5.  Get value of the key\n \
                        6.  find keys with matching prefix\n \
                        7.  Longest matching prefix\n \
                        8.  regex\n \
                        9.  Delete trie\n \
                        0. exit\n \
                        \n");

                scanf("%d",&choice);
                switch(choice) {

			case 0:
				{
					printf("Exiting!!!\n");
					break;
				}
                        case 1 : {
					 char key[100];
					 val value;
					 printf("Enter key\n");
					 scanf("%s",key);
					 printf("Enter value\n");
					 scanf("%d",&value);
					 printf("key = %s, value = %d\n",key,value);
					 trieAdd(&root,key,value);
					 break;

				 }
			case 2:
				{
					char key[100];
					printf("Enter key to be removed\n");
					scanf("%s",key);
					trieRemove(root,key);


					break;
				}
			case 3:
				{
					char key[100];
					printf("Enter a key to be searched\n");
					scanf("%s",key);
					trieIsMember(root,key);
					break;
				}
			case 4: {
					printf("printing keys\n");
					triePrintKeys(root);
					break;
				}
			case 5:
				{
					char key[100];
					printf("Enter the key\n");
					scanf("%s",key);
					//trieGetValue(root,key);
					printf("value = %d\n",trieGetValue(root,key));
					break;
				}
			case 6:
				{
					char prefix[100];
					printf("enter the prefix\n");
					scanf("%s",prefix);
					trieKeyWithMatchingPrefix(root,prefix);
					break;
				}
			case 9:
				{
					destroyTrie(root);
				}
			default:
				{
					printf("Error input\n");
				}
		
		}
	}while (choice !=0);
	return 0;
}
