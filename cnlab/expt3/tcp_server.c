#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000

void main() {
	int server_fd, client_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buff[6];
	
	printf("TCP Server\n");
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	} else {
		printf("Server socket created.\n");
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY; //OR inet_addr("172.20.34.12")
	address.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Binding failed!\n");
		exit(1);
	} else {
		printf("Socket binded.\n");
	}
	
	if(listen(server_fd, 5) < 0) {
		printf("Listening failed!\n");
		exit(1);
	} else {
		printf("Listening.\n");
	}
	
	if((client_fd = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
		printf("Accept failed!\n");
		exit(1);
	} else {
		printf("Connection accepted.\n");
	}
	
	if(recv(client_fd, buff, 6 * sizeof(char), 0) < 0) {
		printf("Receive failed!\n");
		exit(1);
	} else {
		printf("Received message: %s\n", buff);
	}
	
	close(server_fd);
	close(client_fd);
}
