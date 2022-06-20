#include<stdio.h>
#include<string.h>
#define C_SIZE 50

union Address
{
	char name[C_SIZE];
	char house[C_SIZE];
	char city[C_SIZE];
	char state[C_SIZE];
	int pin;
};

void main()
{
	union Address person1;
	printf("\nEnter name: ");
	scanf("%s",person1.name);
	printf("\nEnter house name: ");
	scanf("%s",person1.house);
	printf("\nEnter city name: ");
	scanf("%s",person1.city);
	printf("\nEnter state: ");
	scanf("%s",person1.state);
	printf("\nEnter PIN code: ");
	scanf("%d",&person1.pin);


	printf("\n\nPerson 1 Address: \n");
	printf("NAME: %s\nHOUSE NAME: %s\nCITY: %s\nSTATE: %s\nPIN CODE: %d\n",person1.name,person1.house,person1.city,person1.state,person1.pin);
	//Only PIN CODE will be printed because union can retrieve only one value at a time
} 
