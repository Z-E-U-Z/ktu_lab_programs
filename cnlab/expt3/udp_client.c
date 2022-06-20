#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000

void main() {
	int client_fd;
	struct sockaddr_in serv_addr;
	char buff[] = "HELLO";
	
	printf("UDP Client\n");
	
	if((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	} else {
		printf("Client socket created.\n");
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY; //OR inet_addr("172.20.34.12")
	serv_addr.sin_port = htons(PORT);
	
	if(sendto(client_fd, buff, 6 * sizeof(char), 0, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("Sending failed!\n");
		exit(1);
	} else {
		printf("Message sent: %s\n", buff);
	}
	
    	close(client_fd);
}
