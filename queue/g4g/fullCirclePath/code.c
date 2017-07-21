#include <stdio.h>

void fullCirclePath(int a[][2], int row, int col) {

	int i;
	int petrolLeft = 0;
	int startPos = 0;
	int totalPetrol = 0;
	for(i=0;i<4;i++) {

		petrolLeft += (a[i][0] - a[i][1]);
		totalPetrol += petrolLeft;
		printf("petrol left = %d\n",petrolLeft);	
		if(petrolLeft < 0) {
			petrolLeft -= (a[startPos][0] - a[startPos][1]);
			printf("changing starting pos from %d to %d\n",startPos,startPos+1);
			startPos++;
		}
		
	}

	if(totalPetrol >=0)
		printf("start pos is %d\n",startPos+1);
	else
		printf("there is no circular path\n");
}


int main() {

	int a[][2] = {{4,6},{6,5},{7,3},{4,5}};	

	fullCirclePath(a,4,2);			

	return 0;
}
