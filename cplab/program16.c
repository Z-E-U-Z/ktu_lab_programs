#include<stdio.h>
void swap(int *ptra,int *ptrb)
{
	int temp;
	temp=*ptra;
	*ptra=*ptrb;
	*ptrb=temp;
}
void main()
{
	int a,b,sum,*ptra,*ptrb;
	printf("Enter two numbers\n");
	scanf("%d%d",&a,&b);
	ptra=&a;
	ptrb=&b;
	sum=*ptra+*ptrb;
	printf("The sum of %d and %d is %d\n",*ptra,*ptrb,sum);
	swap(&a,&b);
	printf("After swapping: %d and %d\n",a,b);
}
