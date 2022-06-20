#include<stdio.h>
void main()
{
	int a,num,digitNo=0,product=1,digit,sum=0;
	printf("Enter a natural no.\n");
	scanf("%d",&a);
	num=a;
	//to find the no. of digits
	while(a>0)
	{
		digitNo++;
		a/=10;
	}
	a=num;
	while(num>0)
	{
		digit=num%10;
		for(int i=0;i<digitNo;i++)
		{
			product*=digit;
		}
		sum+=product;
		num/=10;
		product=1;
	}
	if(a==sum)
		printf("ARMSTRONG\n");
	else
		printf("NOT ARMSTRONG\n");
}

