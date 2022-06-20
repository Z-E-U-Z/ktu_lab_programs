#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8000
#define PORT1 8001

int square(int num) {
	return num * num;
}

void main() {
	int server_fd, client_fd1, client_fd2;
	struct sockaddr_in address, cli_addr;
	int opt, addrlen = sizeof(address);
	int num;
	
	printf("Enter 1 (TCP) or 2 (UDP): ");
	scanf("%d", &opt);
	
	if(opt == 1)
		printf("TCP Server\n");
	else if(opt == 2)
		printf("UDP Server\n");
	else {
		printf("Invalid input!\n");
		exit(1);
	}
	
	if(opt == 1) {
		if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			printf("Socket creation failed!\n");
			exit(1);
		} else {
			printf("Server socket created.\n");
		}
	} else {
		if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
			printf("Socket creation failed!\n");
			exit(1);
		} else {
			printf("Server socket created.\n");
		}
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Socket binding failed!\n");
		exit(1);
	} else {
		printf("Socket binded.\n");
	}
	
	if(opt == 1) {
		if(listen(server_fd, 5) < 0) {
			printf("Listening failed!\n");
			exit(1);
		} else {
			printf("Server listening.\n");
		}
		
		if((client_fd1 = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
			printf("Connection failed!\n");
			exit(1);
		} else {
			printf("Connected to client 1.\n");
		}
		
		if((client_fd2 = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
			printf("Connection failed!\n");
			exit(1);
		} else {
			printf("Connected to client 2.\n");
		}
		
		if(recv(client_fd1, &num, sizeof(int), 0) < 0) {
			printf("Receive failed!\n");
			exit(1);
		} else {
			printf("Received integer from client 1: %d\n", num);
		}
		
		int result = square(num);
		
		if(send(client_fd2, &result, sizeof(int), 0) < 0) {
			printf("Send failed!\n");
			exit(1);
		} else {
			printf("Squared integer sent to client 2.\n");
		}
	} else {
		int len = sizeof(address);
		int len1 = sizeof(cli_addr);
		
		cli_addr.sin_port = htons(PORT1);
		
		if(recvfrom(server_fd, &num, sizeof(int), 0, (struct sockaddr*) &address, &len) < 0) {
			printf("Receive failed!\n");
			exit(1);
		} else {
			printf("Received integer from client 1: %d\n", num);
		}
		
		int result = square(num);
		
		if(sendto(server_fd, &result, sizeof(int), 0, (struct sockaddr*) &cli_addr, len1) < 0) {
			printf("Send failed!\n");
			exit(1);
		} else {
			printf("Squared integer sent to client 2.\n");
		}
	}
	
	close(server_fd);
	close(client_fd1);
	close(client_fd2);
}
