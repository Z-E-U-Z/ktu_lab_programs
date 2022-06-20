#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

char* get() {
	return "Hello, Welcome!";
}

char* post(char* body) {
	return "Body posted!";
}

void main(int PORT) {
	int server_fd, client_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buff[20];
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Binding failed!\n");
		exit(1);
	}
	
	while(1) {
		if(listen(server_fd, 5) < 0) {
			printf("Listening failed!\n");
			exit(1);
		} else {
			printf("Server is running and listening for requests...\n");
		}
		
		if((client_fd = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
			printf("Accept failed!\n");
			exit(1);
		} else {
			printf("Request accepted.\n");
		}
		
		if(recv(client_fd, buff, 20 * sizeof(char), 0) < 0) {
			printf("Receive failed!\n");
			exit(1);
		} else {
			printf("Request: %s\n", buff);
			
			if(!strcmp(buff, "get") {
				buff = get();
				
				if(send(client_fd, buff, 20 * sizeof(char), 0) < 0)
					printf("Receive failed!\n");
			} else if(!strcmp(buff, "post") {
				if(recv(client_fd, buff, 20 * sizeof(char), 0) < 0)
					printf("Receive failed!\n");
					
				buff = post(buff);
			} else {
				buff = "Invalid request";
				
				if(send(client_fd, buff, 20 * sizeof(char), 0) < 0)
					printf("Receive failed!\n");
			}
		}
	}
	
	close(server_fd);
	close(client_fd);
}
