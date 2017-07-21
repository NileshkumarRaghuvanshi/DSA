#include <stdio.h>
#include "queue.h"

int main() {
	
	Qptr Q = createQ();
	nQ(Q,10);
	nQ(Q,20);
	nQ(Q,30);
	nQ(Q,40);
	nQ(Q,50);

	//printf("dQ = %d %d %d %d %d %d\n",dQ(Q),dQ(Q),dQ(Q),dQ(Q),dQ(Q),dQ(Q));
	printf("dQ = %d\n",dQ(Q));
	printf("dQ = %d\n",dQ(Q));
	printf("dQ = %d\n",dQ(Q));
	printf("dQ = %d\n",dQ(Q));
	printf("dQ = %d\n",dQ(Q));
	printf("dQ = %d\n",dQ(Q));

	return 0;
}
