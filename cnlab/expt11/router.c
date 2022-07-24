#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void display(int num, int dist_vector[][num]) {
	printf("Distance vector: \n ");
	
	for(int i = 0; i < num; i++)
		printf(" %d", i + 1);
	
	printf("\n");
	
	for(int i = 0; i < num; i++) {
		printf("%d ", i + 1);
		
		for(int j = 0; j < num; j++)
			printf("%d ", dist_vector[i][j]);
		
		printf("\n");
	}
}

void main(int argc, char* argv[]) {
	int PORT, num;
	
	if(argc == 3) {
		PORT = atoi(argv[1]);
		num = atoi(argv[2]);
	}
	else {
		printf("Enter port and number of routers!\n");
		exit(1);
	}
	
	struct sockaddr_in address, cli_addr;
	int server_fd;
	int addrlen = sizeof(address), len = sizeof(cli_addr);
	int dist_vector[num][num];
	
	printf("DVR Router\n");
	
	printf("Enter distance vector:\n");
	for(int i = 0; i < num; i++)
		for(int j = 0; j < num; j++)
			scanf("%d", &dist_vector[i][j]);
	
	display(num, dist_vector);
	
	if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Socket binding failed!\n");
		exit(1);
	}
	
	if(sendto(server_fd, dist_vector, 100 * sizeof(int), 0, (struct sockaddr*) &cli_addr, len) < 0) {
		printf("Send failed!\n");
		exit(1);
	} else {
		printf("Result sent to client.\n");
	}
	
	if(recvfrom(server_fd, dist_vector, 100 * sizeof(int), 0, (struct sockaddr*) &cli_addr, &len) < 0) {
		printf("Receive failed!\n");
		exit(1);
	} else {
		if(sendto(server_fd, dist_vector, 100 * sizeof(int), 0, (struct sockaddr*) &cli_addr, len) < 0) {
			printf("Send failed!\n");
			exit(1);
		} else {
			printf("Result sent to client.\n");
		}
	}
	
	close(server_fd);
}
