#include <stdio.h>
#include <malloc.h>

#include "tree.h"

TreeADT MyRoot = NULL;
int main() {

	printf("Namste, tree program me apka swagat he!!!\n");

        int choice = 0;
        do {

                printf("Hello Welcome to tree programm!!!\n \
                        please select any one of these option:\n \
                        1. Insert a node.\n \
                        2. Remove a node.\n \
                        3. search a node.\n \
                        4. traverse preorder\n \
                        5. traverse postorder\n \
                        6. traverse inorder\n \
                        7. Delete a tree\n \
                        8. Level order traversal\n \
                        9. Level order in reverse way\n \
                        0. exit\n \
                        \n");

		scanf("%d",&choice);
		switch(choice) {

			case 1 : {
					printf("AVL insert\n");
					printf("Enter a node\n");
					int data; 
					scanf("%d",&data);
					if(AVLInsert(&MyRoot,data) >= 0)
						printf("SUCCESS : NODE IS INSERTED\n");
					else
						printf("FAILURE : NODE IS NOT INSERTED\n");
					break;
				 }
			case 4 : {
					 PrintAVLTree(&MyRoot);
					 break;
				 }
                        case 7 : {
					break;
				 }
			case 0: {
					printf("see you again\n");
					break;
				}
			default : {
					  printf("No match\n");
				  }


		}
	}while (choice !=0);

	return 0;
}

