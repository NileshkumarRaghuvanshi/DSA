#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>

#include "soapIPC.h"


int  main() {
	
	printf("Server Code\n");
	int ret;
	soapTransactionInfo_t soapRxTx;
	int noOfBytes;
	int server_pipe_fd;
	
	if(access(SOAP_HIST_PIPE,F_OK) == -1) {
		ret = mkfifo(SOAP_HIST_PIPE,0777);
		if(ret !=0) {
			printf("Error creating pipe, error = %s\n",strerror(errno));
			return errno;
		}
	}

	server_pipe_fd = open(SOAP_HIST_PIPE, O_RDONLY);
	if(server_pipe_fd == -1) {
		printf("Error opening a pipe, error = %s\n",strerror(errno));
		return errno;
	}

	
	while(1) {
		//sleep(2);
		printf("reading to see data is present\n");
		noOfBytes = read(server_pipe_fd,&soapRxTx,sizeof(soapRxTx));
		if(noOfBytes > 0) {
			printf("Data read succsfully\n");
			printf("timestamp = %lu\n",soapRxTx.timestamp);
			printf("ip = %s\n",soapRxTx.ip);
			printf("request = %s\n",soapRxTx.soapRequest);
		}
		else if (noOfBytes == 0){
			printf("No data in the pipe\n");
			close(server_pipe_fd);
			//unlink(SOAP_HIST_PIPE);
			
			printf("waiting for new client requests\n");
			server_pipe_fd = open(SOAP_HIST_PIPE, O_RDONLY);
			if(server_pipe_fd == -1) {
				printf("Error opening a pipe, error = %s\n",strerror(errno));
                		return errno;
        		}
			else
				printf("server is available again!!!\n");
		}
		else
			printf("ERROR reading\n");
	}

	return 0;

}



