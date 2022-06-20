#include<stdio.h>
void main()
{
	char *str="Hello World";
	int *arr[3];
	int a=1;
	arr[0]=&a;
	printf("%p %p %d %d",*arr,arr[0],**arr,*arr[0]);
	printf("%s %c %p",str,*str,str);
}

