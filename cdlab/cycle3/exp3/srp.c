#include <stdio.h>
#include <string.h>

typedef struct stack {
	int top;
	char arr[20];
} stack;

typedef struct prod {
	char lhs[10];
	char rhs[10];
} prod;

typedef struct terminal {
	char c;
	int priority;
} terminal;

terminal terminals[10];
int t = 0,

void initStack(stack* st) {
	st->top = -1;
}

void push(stack* st, char c) {
	st->arr[st->top++] = c;
}

char pop(stack* st) {
	char c = st->arr[st->top--];
	return c;
}

char seek(stack* st) {
	return st->arr[st->top];
}

int priority(c) {
	for(int i = 0; i < t; i++) {
		if(terminals[i].c == c)
			return terminals[i].priority;
	}
	
	return -1;
}

int checkAccept() {
	return 0;
}

void main() {
	int n;
	prod grammar[30];
	stack st;
	char input[20];
	int ip = 0;
	
	initStack(&st);
	
	push(&st, '$');

	printf("Enter the number of productions: ");
	scanf("%d", &n);
	
	printf("\nEnter the productions (Eg: S = aBc):\n");
	for(int i = 0; i < n; i++) {
		scanf("%s = %s", grammar[i].lhs, grammar[i].rhs);
	}
	
	int flag;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < strlen(grammar[i].rhs); j++) {
			if(grammar[i].rhs[j] < 'A' || grammar[i].rhs[j] > 'Z') {
				flag = 0;
				
				for(int k = 0; k < t; k++) {
					if(terminals[k].c == grammar[i].rhs[j])
						flag = 1;
				}
				
				if(!flag) {
					terminals[t++].c = grammar[i].rhs[j];
				}
			}
		}
	}
	
	printf("\nEnter priority (0 - lowest, 10 - highest):\n");
	for(int i = 0; i < t; i++) {
		printf("%c: ", terminals[i].c);
		scanf("%d", &terminals[i].priority);
	}
	
	printf("\nEnter the input string: ");
	scanf("%s", input);
	
	input[strlen(input) + 1] = '\0';
	input[strlen(input)] = '$';
	
	char c;
	
	while(1) {
		if(priority(seek(&st)) > priority(input[ip])) {
			// SHIFT
			
			push(&st, input[ip++]);
		} else {
			// REDUCE
			
			c = seek(&st);
			
			for(int i = 0; i < n; i++) {
				
			}
		}
		
		if(checkAccept()) {
			printf("\Accepted.\n");
			break;
		}
	}
}
