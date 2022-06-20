#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
	char* args[] = {"./amal", NULL};
	
	if(fork() == 0)
		execvp(args[0], args);
	else
		wait(NULL);
		
	printf("Amal\n");
}
