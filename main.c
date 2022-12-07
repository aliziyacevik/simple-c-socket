#include<stdio.h>
#include<string.h>
#include <errno.h>

#include<sys/socket.h> 
#include <arpa/inet.h>

#define MAX_CONNECTIONS 96
#define ERROR 1

int main(int argc , char *argv[])
{
	int server_socket, client_socket;
	struct sockaddr_in sock_addr, client_addr;
	

	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
	{
		perror("Failed to create socket");
		return 1;
	}

	memset(&(sock_addr.sin_zero), 0, sizeof(sock_addr.sin_zero));
	
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sock_addr.sin_port = htons(1024);
	
	printf("%d", sock_addr.sin_addr.s_addr);

	if(bind(server_socket, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) == -1) {
		perror("failed to bind socket");
	}
	
		
	if(listen(server_socket, MAX_CONNECTIONS) == -1) {
		perror("failed to listen");
	}


		
	printf("fas");
	int addrLen = sizeof(client_addr);
	client_socket = accept(server_socket, (struct sockaddr *) &client_addr,  &addrLen);
	if( client_socket < 0) {
			perror("failed to accept");
		}
	
	return 0;
}
