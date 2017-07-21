#include <stdio.h>
#include <malloc.h>

int max (int a, int b) {
	return (a>b)?a:b;
}

void printArray(int *a, int size) {

	int i =0;
	for(i=0; i<size; i++)
		printf("%d ",a[i]);

	printf("\n");
}

void findMaxProfitByRodCutting(int *price, int size) {


	int i=0;
	int j =0;
	int *best = calloc(sizeof(int),(size+1));
	int maxProfit = 0;

	for(i=1; i<=size; i++) {

		for(j=i; j>0; j--) {

			
			maxProfit= max(maxProfit, price[j-1] +best[i-j]);
			printf("j = %d price = %d best = %d profit = %d\n",j,price[j-1],best[i-j],maxProfit);
		}
		
		if(maxProfit > best[i])
			best[i] = maxProfit;

		printArray(best,size+1);
	}

	printArray(best,size+1);
	printf("Max profit %d\n",best[size]);
}


int main() {


	int price[] = {1,5,8,9,10,17,17,20};
	findMaxProfitByRodCutting(price, sizeof(price)/sizeof(price[0]));
	return 0;

}
