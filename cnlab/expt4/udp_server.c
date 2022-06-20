#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000

float findMin(float *buff, int n) {
	int min = 0;
	for(int i = 0; i < n; i++) {
		if (buff[min] > buff[i])
			min = i;
	}
	return buff[min];
}

float findMax(float *buff, int n) {
	int max = 0;
	for(int i = 0; i < n; i++) {
		if (buff[max] < buff[i])
			max = i;
	}
	return buff[max];
}

float findAvg(float *buff, int n) {
	float avg = 0;
	for(int i = 0; i < n; i++) {
		avg += buff[i];
	}
	avg /= n;
	return avg;
}

void main() {
	int server_fd, client_fd;
	struct sockaddr_in address, cli_addr;
	int n, addrlen = sizeof(address);
	float *buff, output[3];
	
	printf("TCP Server\n");

	
	if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	} else {
		printf("Server socket created.\n");
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
	
	int len = sizeof(cli_addr);
	
	if(recvfrom(server_fd, &n, sizeof(int), 0, (struct sockaddr*) &cli_addr, &len) < 0) {
		printf("Receive failed!\n");
		exit(1);
	} else {
		buff = (float*) malloc(n * sizeof(float));
		
		if(recvfrom(server_fd, buff, n * sizeof(float), 0, (struct sockaddr*) &cli_addr, &len) < 0) {
			printf("Receive failed!\n");
			exit(1);
		} else {
			printf("Received data:");
			for(int i = 0; i < n; i++) {
				printf(" %.1f", buff[i]);
			}
			printf("\n");
		}
	}
	
	printf("Calculating min, max and avg.\n");
	output[0] = findMin(buff, n);
	output[1] = findMax(buff, n);
	output[2] = findAvg(buff, n);
	
	if(sendto(server_fd, output, 3 * sizeof(float), 0, (struct sockaddr*) &cli_addr, len) < 0) {
		printf("Send failed!\n");
		exit(1);
	} else {
		printf("Result sent to client.\n");
	}
	
	close(server_fd);
	close(client_fd);
}
