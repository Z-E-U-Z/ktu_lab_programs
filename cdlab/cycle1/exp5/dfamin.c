#include <stdio.h>
#include <string.h>

typedef struct trans {
	char state1[3];
	char input;
	char state2[3];
} trans;

typedef struct state {
	int len;
	char states[10][3];
} state;

typedef struct trans1 {
	state state1;
	char input;
	state state2;
} trans1;

// DFA data
int n, f, m, l;
char states[10][3], start[3], final[10][3], alpha[5];
trans table[50];

// Minimised DFA data
int n1, f1, m1, l;
state states1[10], start1, final1[10];
trans1 table1[50];

int isFinal(char state[]) {
	int flag = 0;

	for(int i = 0; i < f; i++) {
		if(!strcmp(final[i], state))
			flag = 1;
	}
	
	return flag;
}

int goTo(char st[],  char c) {
	for(int i = 0; i < m; i++) {
		if(!strcmp(table[i].state1, st) && table[i].input == c) {
			for(int j = 0; j < n; j++) {
				if(!strcmp(states[j], table[i].state2))
					return j;
			}
		}
	}
}

void addState(state* states, int i, char st[]) {
}

void main() {
	// Reading the DFA
	printf("Enter the no of states: ");
	scanf("%d", &n);
	
	printf("Enter the states:\n");
	for(int i = 0; i < n; i++) {
		scanf("%s", states[i]);
	}
	
	printf("Enter the start state: ");
	scanf("%s", start);
	
	printf("Enter the number of final states: ");
	scanf("%d", &f);
	
	printf("Enter the final states\n");
	for(int i = 0; i < f; i++) {
		scanf("%s", final[i]);
	}
	
	printf("Enter the number of alphabets: ");
	scanf("%d", &l);
	
	printf("Enter the alphabets\n");
	for(int i = 0; i < l; i++) {
		scanf(" %c", &alpha[i]);
	}
	
	m = 0;
	printf("Enter the transitions\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < l; j++) {
			strcpy(table[m].state1, states[i]);
			table[m].input = alpha[j];
			printf("%s %c ", states[i], alpha[j]);
			scanf("%s", table[m].state2);
			m++;
		}
	}
	
	// Minimising using Myhill-Nerode Theorem
	int mTbl[n][n];
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			mTbl[i][j] = 0;
		}
	}
	
	// Marking if either state is final but not both
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if((isFinal(states[i]) && !isFinal(states[j])) || (!isFinal(states[i]) && isFinal(states[j])) ) {
				mTbl[i][j] = 1;
			}
		}
	}
	
	int s1, s2, flag;
	
	// Marking the states by checking if their transitions are marked
	do {
		flag = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(mTbl[i][j])
					continue;
				
				for(int k = 0; k < l; k++) {
					s1 = goTo(states[i], alpha[k]);
					s2 = goTo(states[j], alpha[k]);
					
					if(mTbl[s1][s2]) {
						mTbl[i][j] = 1;
						flag = 1;
					}
				}
			}
		}
	} while(flag);
	
	// Combining states
	n1 = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(!mTbl[i][j]) {
				strcpy(states1[n1].states[0], states[i]);
				strcpy(states1[n1].states[1], states[j]);
				states1[n1].len = 2;
				n1++;
			}
		}
	}

	for(int i = 0; i < n1; i++) {
		for(int j = 0; j < states1[i].len; j++) {
			printf("%s ", states1[i].states[j]);
		}
		printf("\n");
	}
	
	// Transition table of min DFA
	
	// Start state of min DFA
	
	// Final states of min DFA
	
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", mTbl[i][j]);
		}
		printf("\n");
	}*/
}
