#include<stdio.h>
void reverse(char a[])
{
	char b[20];
	int l=0,i,j;
	for(i=0;i<20;i++)
	{
		if(a[i]=='\0')
			break;
		else
			l++;
	}
	for(i=0,j=l-1;i<l&&j>=0;i++,j--)
		b[i]=a[j];
	b[l]='\0';
	printf("The reverse of %s is %s\n",a,b);
}

void main()
{
	char a[20],b[20];
	printf("Enter the word\n");
	scanf("%s",a);
	reverse(a);
}

