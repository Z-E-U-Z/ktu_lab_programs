#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000

void main() {
	int server_fd;
	struct sockaddr_in serv_addr, cli_addr;
	char buff[6];
	
	printf("UDP Server\n");
	
	if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	} else {
		printf("Server socket created.\n");
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY; //OR inet_addr("172.20.34.12")
	serv_addr.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("Binding failed!\n");
		exit(1);
	} else {
		printf("Socket binded.\n");
	}
	
	int len = sizeof(cli_addr);
	
    	if(recvfrom(server_fd, (char*) buff, 6 * sizeof(char), 0, (struct sockaddr*) &cli_addr, &len) < 0) {
    		printf("Receive failed!\n");
		exit(1);
	} else {
		printf("Received message: %s\n", buff);
    	}
    	
    	close(server_fd);
}
