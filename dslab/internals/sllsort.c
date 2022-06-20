#include<stdio.h>
#include<stdlib.h>

struct node
{
	int* arr;
	struct node* LINK;
};

int m, n;

void createList(struct node* ptr)
{
	printf("Enter the value of n\n");
	scanf("%d", &n);
	printf("Enter the value of m\n");
	scanf("%d", &m);
	
	printf("Enter the numbers\n");
	
	for(int i=0; ; )
	{
		ptr->LINK = (struct node*) malloc(sizeof(struct node));
		ptr->LINK->arr = malloc(m*sizeof(int));
		
		for(int j=0; j<m; j++)
		{
			scanf("%d", &ptr->LINK->arr[j]);
			i++;
			
			if(i == n)
				return;
		}
		ptr = ptr->LINK;
	}
}

void sortArray(int* A, int m)
{
	for(int i=0; i < m-1; i++)
	{
		int min = i;
		
		for(int j=i+1; j < m; j++)
			if(A[j] < A[min])
				min = j;

		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}

void sort(struct node* ptrP)
{
	struct node* ptr = ptrP->LINK;
	
	while(ptr != NULL)
	{
		int min = ptr->arr[0];
		struct node* minP = ptrP;
		struct node* minNode = ptr;
		
		struct node* ptr1P = ptr;
		struct node* ptr1 = ptr->LINK;
		
		while(ptr1 != NULL)
		{
			if(ptr1->arr[0] < min)
			{
				min = ptr1->arr[0];
				minP = ptr1P;
				minNode = ptr1;
			}
			ptr1P = ptr1;
			ptr1 = ptr1->LINK;
		}
		
		struct node* temp = ptrP->LINK;
		ptrP->LINK = minP->LINK;
		minP->LINK = temp;
		
		temp = ptr->LINK;
		ptr->LINK = minNode->LINK;
		minNode->LINK = temp;
		
		ptrP = ptr;
		ptr = ptr->LINK;
	}
}

void sortList(struct node* ptr)
{
	while(ptr != NULL)
	{
		int min = ptr->arr[0];
		struct node* minNode = ptr;
		struct node* ptr1 = ptr->LINK;
		int *temp;
		
		while(ptr1 != NULL)
		{
			if(ptr1->arr[0] < min)
			{
				min = ptr1->arr[0];
				minNode = ptr1;
			}
			ptr1 = ptr1->LINK;
		}
		
		temp = minNode->arr;
		minNode->arr = ptr->arr;
		ptr->arr = temp;
		
		ptr = ptr->LINK;
	}
}

void display(struct node* ptr)
{
	printf("The list: \n");
	for(int i=0; ; )
	{
		for(int j=0; j<m; j++)
		{
			if(ptr->arr[j] != 0)
			{
				printf("%d ", ptr->arr[j]);
				i++;
					
				if(i == n)
					return;
			}
		}
		
		printf("\n");
		
		ptr = ptr->LINK;
	}
}

void main()
{
	struct node* HEADER = (struct node*) malloc(sizeof(struct node));
	
	createList(HEADER);
	display(HEADER->LINK);
	
	struct node* ptr = HEADER->LINK;
	
	int flag = m;
	
	while(ptr != NULL)
	{
		if(ptr->LINK == NULL)
			flag = n % m;
		sortArray(ptr->arr, flag);
		ptr = ptr->LINK;
	}
	
	printf("\n\nAfter array sort\n");
	display(HEADER->LINK);
	
	sortList(HEADER->LINK);
	//sort(HEADER); //Interchanging links
	
	printf("\n\nAfter list sort\n");
	display(HEADER->LINK);
	printf("\n");
}
