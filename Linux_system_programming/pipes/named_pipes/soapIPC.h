//This is file that define the IPC communication to send
//data between many sender and a reciever


#define SOAP_HIST_PIPE "soap"

typedef struct soapTransactionInfo {
	time_t timestamp;
	char ip[30];
	char soapRequest[100];
} soapTransactionInfo_t ;
