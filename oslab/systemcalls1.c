#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void fibonacci(int n) {
	int x = 0, y = 1;
	
	while(y < n) {
		printf("%d ", y);
		int temp = y;
		y = x + y;
		x = temp;
	}
}

void prime(int n) {
	for (int i = 2; i < n; i++) {
		int flag = 0;
		
		for (int j = 2; j < i / 2; j++) {
			if (i % j == 0)
				flag = 1;
		}
		
		if (flag == 0)
			printf("%d ", i);
	}
}

void main() {
	int n;
	
	printf("Enter the value of N: ");
	scanf("%d", &n);
	
	pid_t pid = fork();
	
	if(pid == 0) {
		printf("Child (Fibonacci): ");
		fibonacci(n);
		printf("\n");
	}
	else if (pid == -1)
		printf("Child could not be created!\n");
	else {
		wait(NULL);	
		printf("Parent (Prime): ");
		prime(n);
		printf("\n");
	}
}
