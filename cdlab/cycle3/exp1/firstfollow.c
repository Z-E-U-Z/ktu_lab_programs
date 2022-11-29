#include <stdio.h>
#include <stdlib.h>

typedef struct prod {
	char lhs[10];
	char rhs[10];
} prod;

typedef struct firstStruct {
	char arr[10];
	int count;
} firstStruct;

typedef struct followStruct {
	char arr[10];
	int count;
} followStruct;

int n;
prod grammar[30];
char temps[] = "PQRUVWXYZ";
int tempIndex = 0;

int contains(firstStruct* f, char c) {
	for(int i = 0; i < f->count; i++) {
		if(f->arr[i] == c)
			return 1;
	}
	
	return 0;
}

firstStruct* first(char c) {
	firstStruct* f = (firstStruct*) malloc(sizeof(firstStruct));
	f->count = 0;
	int flag;
	
	for(int i = 0; i < n; i++) {
		if(grammar[i].lhs[0] == c) {
			if(grammar[i].rhs[0] >= 'A' && grammar[i].rhs[0] <= 'Z') { // RHS starts with non-terminal
				for(int j = 0; ; j++) {
					if(grammar[i].rhs[j] == '\0') {
						break;
					}
					
					firstStruct* f1 = first(grammar[i].rhs[j]);
					
					if(contains(f1, 'e')) {
						for(int k = 0; k < f1->count; k++) {
							flag = 0;
							
							for(int l = 0; l < f->count; l++) {
								if(f1->arr[k] != 'e' && f->arr[l] == f1->arr[k]) {
									flag = 1;
								}
							}
							
							if(!flag)
								f->arr[f->count++] = f1->arr[k];
						}
						
						continue;
					}
					else {
						for(int k = 0; k < f1->count; k++) {
							flag = 0;
							
							for(int l = 0; l < f->count; l++) {
								if(f->arr[l] == f1->arr[k]) {
									flag = 1;
								}
							}
							
							if(!flag)
								f->arr[f->count++] = f1->arr[k];
						}
						
						break;
					}
				}
			} else { // RHS starts with terminal
				flag = 0;
				for(int j = 0; j < f->count; j++) {
					if(f->arr[j] == grammar[i].rhs[0]) {
						flag = 1;
					}
				}
				
				if(!flag)
					f->arr[f->count++] = grammar[i].rhs[0];
			}
		}
	}

	return f;
}

void follow(char c) {
	for(int i = 0; i < n; i++) {
		//if()
	}
}

void main() {
	int t1 = 0, t2 = 0;
	char non_terminals[10];
	char terminals[10];
	
	printf("Enter the number of productions: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%s = %s", grammar[i].lhs, grammar[i].rhs);
	}
	
	int flag;
	
	for(int i = 0; i < n; i++) {
		flag = 0;
		
		for(int j = 0; j < t1; j++) {
			if(non_terminals[j] == grammar[i].lhs[0])
				flag = 1;
		}
		
		if(!flag) {
			non_terminals[t1++] = grammar[i].lhs[0];
		}
		
		for(int j = 0; ; j++) {
			if(grammar[i].rhs[j] == '\0')
				break;
			else if(grammar[i].rhs[j] >= 'A' && grammar[i].rhs[j] <= 'Z') {
				flag = 0;
				
				for(int k = 0; k < t1; k++) {
					if(non_terminals[k] == grammar[i].rhs[j])
						flag = 1;
				}
				
				if(!flag) {
					non_terminals[t1++] = grammar[i].rhs[j];
				}
				
				continue;
			}
			
			flag = 0;
			
			for(int k = 0; k < t2; k++) {
				if(terminals[k] == grammar[i].rhs[j])
					flag = 1;
			}
			
			if(!flag) {
				terminals[t2++] = grammar[i].rhs[j];
			}
		}
	}
	
	// Eliminating left recursion
	for(int i = 0; i < n; i++) {
		if(grammar[i].lhs[0] == grammar[i].rhs[0]) {
			for(int j = 0; ; j++) {
				if(grammar[i].rhs[j + 1] == '\0') {
					grammar[i].rhs[j] = temps[tempIndex];
					break;
				}
				
				grammar[i].rhs[j] = grammar[i].rhs[j + 1];
			}
					
			for(int j = 0; j < n; j++) {
				if(j == i)
					continue;
				
				if(grammar[j].lhs[0] == grammar[i].lhs[0]) {
					for(int k = 0; ; k++) {
						if(grammar[j].rhs[k] == '\0') {
							grammar[j].rhs[k] = temps[tempIndex];
							grammar[j].rhs[k + 1] = '\0';
							break;
						}
					}
				}
			}

			grammar[i].lhs[0] = temps[tempIndex];
			grammar[n].lhs[0] = temps[tempIndex];
			grammar[n].lhs[1] = '\0';
			grammar[n].rhs[0] = 'e';
			grammar[n].rhs[1] = '\0';
			n++;
			tempIndex++;
		}
	}
	
	firstStruct* f;
	
	printf("\n");
	for(int i = 0; i < t1; i++) {
		printf("FIRST(%c):", non_terminals[i]);
		
		f = first(non_terminals[i]);
		
		for(int j = 0; j < f->count; j++) {
			printf(" %c", f->arr[j]);
		}
		
		printf("\n");
	}
	
	printf("\n");
	for(int i = 0; i < t1; i++) {
		follow(non_terminals[i]);
	}
}
