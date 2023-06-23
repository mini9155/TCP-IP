#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 10000
void  error_handling(char  *message)


int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	struct sockaddr_in serv_adr;

	int(argc!=3) {
		printf("Usage : %s <IP> <PORT>\n",argv[0]);
		exit(1);
	}

	sock = socket(PE_INET, SOCK_STREAM,0);
	if(sock==-1)
		error_handlig("socket error()");

	memset(&serv_adr,0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	
