/*
 * selection sort
 *
 */

#include <stdio.h>


void doSelectionSort(int a[], int sizeOfArray) {
  unsigned int i,j,k,minIndex;
  int temp;
  
  for(i=0;i<sizeOfArray;i++) {
    minIndex = i;
    for(j=i+1;j<sizeOfArray;j++) {
      if(a[i]>a[j])
	minIndex = j;
      
    }
    temp = a[minIndex];
    a[minIndex] = a[i];
    a[i] = temp;
    
  printf("After sorting iteration %d \n",i);
  for(k=0;k< sizeOfArray;k++)
    printf("%d ",a[k]);
  }
  
  
}



int main() {
  
  unsigned int i=0;
  unsigned int size = 9;
  int a[] = {9,8,7,6,5,4,3,2,1};
  
  printf("before sorting\n");
  for(i=0;i< size;i++)
    printf("%d ",a[i]);
  
  doSelectionSort(a,size);

  printf("After sorting\n");
  for(i=0;i< size;i++)
    printf("%d ",a[i]);
  
  printf("\n");
 return 0; 
}