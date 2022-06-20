#include<stdio.h>
#include<string.h>
void main()
{
	char str[30];
	int i,l=0;
	printf("Enter a word\n");
	scanf("%s",str);
	for(i=0;i<30;i++)
	{
		if(str[i]=='\0')
			break;
		else
			l++;
	}
	for(i=0;i<=l/2;i++)
	{
		if(str[i]==str[l-i-1])
			continue;
		else
		{
			printf("NOT PALINDROME\n");
			break;	
		}
	}
	if(i>l/2)
		printf("PALINDROME\n");
}

