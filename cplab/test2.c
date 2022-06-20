#include<stdio.h>
void main()
{
	int a=5,b=a;
	a>>=1;
	printf("%d %d %d",a,b<<1,b&1);
}

