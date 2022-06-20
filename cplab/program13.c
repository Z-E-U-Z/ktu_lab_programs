#include<stdio.h>

int fact(int n)
{
	if(n==0)
		return 1;
	return n*fact(n-1);
}

void main()
{
	int n,num,fc=1;
	printf("\nEnter a positive integer: ");
	scanf("%d",&n);
	num=n;
	while(num>0)
	{
		fc*=num;
		num--;
	}
	printf("\nFactorial using recursive function = %d",fact(n));
	printf("\nFactorial without using recursive function = %d\n",fc);
}
