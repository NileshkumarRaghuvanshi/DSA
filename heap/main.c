#include <stdio.h>
#include "heap.h"


int main() {

	struct heapRoot *heap = 0;
        int choice = 0;
        do {

                printf("Hello Welcome to tree programm!!!\n \
                        please select any one of these option:\n \
                        1.  Insert a node.\n \
                        2.  Remove a node.\n \
                        3.  Search a node.\n \
                        4.  Print Heap\n \
                        5.  Get Min or Max\n \
                        6.  Heap sort\n \
                        7.  Build heap\n \
                        8.  Create Max Heap\n \
			9.  Create Min Heap\n \
			10. Delete Heap\n \
                        0. exit\n \
                        \n");

                scanf("%d",&choice);
                switch(choice) {

                        case 1 : {
					DATA node;
                                        printf("Heap insert\n");
                                        printf("Enter a node\n");
					scanf("%d",&node);
					if(!heap) {
						int MaxHeap;
						printf("Enter 1 for Max heap and 0 for Min Heap\n");
						scanf("%d",&MaxHeap);
						heap = createHeap(MaxHeap);
						if(heap)
							printf("%s Heap Created!!!\n",(MaxHeap?"Max":"Min"));
						else
							printf("%s Heap Creation failed!!!\n",(MaxHeap?"Max":"Min"));
					}
                                        if(insertHeap(heap,node))
                                        	printf("MAIN : successfully added to Heap!!!\n");
                                        else
	                                	printf("MAIN : Error adding to Heap!!!\n");
					break;
				 }
                        case 2 : {
                                        printf("Remove Min or Max node node!!!\n");
					DATA minVal = removeHeap(heap);
					if(minVal >0)
						printf("Min or max from the heap is %d\n",minVal);
					else
						printf("Error getting root value from the Heap\n");
					break;
				 }
                        case 3 : {
                                        printf("AVL insert\n");
                                        printf("Enter a node\n");
					break;
				 }
                        case 4 : {
                                        int i=0;
					int size = getSize(heap);
					printf("Print Heap\n");
					if(heap) {
						for(i=1;i<=size;i++)
							printf("%d ",getiElement(heap,i));
					}
					else
						printf("Heap is empty. nothing to print!!!\n");
					printf("\n");
					break;
				 }
                        case 5 : {
                                        printf("AVL insert\n");
                                        printf("Enter a node\n");
					break;
				 }
                        case 6 : {
                                        printf("Heap sort\n");
					DATA minVal;
					int i, size = getSize(heap);
					for(i = size ; i>0; i--)
						printf("SORT : %d\n",removeHeap(heap));

                                        //while(minVal = removeHeap(heap) > 0)
                                         //       printf("SORT : %d\n",minVal);
					
					printf("\n");
					break;
				 }
                        case 7 : {
					int noOfElement,i;
					DATA arr[MAX_HEAP_SIZE];
					printf("Build Heap\n");
					printf("enter integer elements one by one. Max size = %d\n", MAX_HEAP_SIZE);
					printf("enter no of elements\n");
					scanf("%d",&noOfElement);

					for (i = 0; i < noOfElement ; i++) {
						scanf("%d",&arr[i]);
					}
					//for (i = 0; i < noOfElement ; i++) {
					//	printf("%d",arr[i]);
					//}
					heap = createHeap(0);
					buildHeap(heap,arr,noOfElement);
					
					break;
				 }
                        case 8 : {
                                        printf("Create Max Heap\n");
                                        heap = createHeap(1);
					if(heap)
						printf("Max Heap Created!!!\n");
					else
						printf("Max Heap creation failed!!!\n");
					break;
				 }
                        case 9 : {
                                        printf("Create Min Heap\n");
                                        heap = createHeap(0);
					if(heap)
						printf("Min Heap Created!!!\n");
					else
						printf("Min Heap creation failed!!!\n");

					break;
				 }
                        case 10 : {
                                        printf("Delete Heap\n");
					destroyHeap(heap);
					heap = NULL;
					break;
				 }

			case 0 : {
					printf("See ya!!\n");
					if(heap) 
						destroyHeap(heap);
					break;
				 }
		}
	} while(choice !=0);



	return 0;
}
