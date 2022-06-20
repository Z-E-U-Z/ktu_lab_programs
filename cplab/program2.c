#include<stdio.h>
void main()
{
	int a,i;
	printf("Enter a natural number\n");
	scanf("%d",&a);
	if(a==1)
		printf("The no. is not prime\n");
	else
	{
		for(i=2;i<=a/2;i++)
		{
			if(a%i==0)
			{
				printf("The no. is not prime\n");
				break;
			}
		}
		if(i>a/2)
			printf("The no. is prime\n");
	}
}

