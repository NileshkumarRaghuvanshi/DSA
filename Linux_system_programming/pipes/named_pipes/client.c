#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "soapIPC.h"

int main() {

	printf("Jai Shri Krishna!!!\n");
	int ret;
	int client_soap_fd;
	soapTransactionInfo_t soapRxTx;
	client_soap_fd = open(SOAP_HIST_PIPE,O_WRONLY);
	if(ret == -1) {
		printf("Error opening a pipe, error %s",strerror(errno));
		return errno;
	}
	else
		printf("succesfully opened a pipe\n");
	
	//printf("sleeping for 4 sec\n");
	//sleep(4);
	
	soapRxTx.timestamp = time(NULL);
	strcpy(soapRxTx.ip,"127.0.0.1");
	soapRxTx.ip[strlen("127.0.0.1")]= '\0';
	strcpy(soapRxTx.soapRequest,"getBladeInfo");
	soapRxTx.soapRequest[strlen("getBladeInfo")] = '\0';
	

	ret = write(client_soap_fd,&soapRxTx,sizeof(soapRxTx));
	if(ret > 0) {
		printf("succesfully written data\n");
	}

	close(client_soap_fd);


	return 0;

}
