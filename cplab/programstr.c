#include<stdio.h>
#include<string.h>
void main()
{
	char s[]="Hello ",t[]="World",u[]="                          ",r[]="HELLO WORLD";
	strcpy(u,r);
	strcat(s,t);
	printf("%zu\n",strlen(u));
	puts(u);
	puts(s);
	char a[]="Amalnath",b[]="Amarnath";
	if(strcmp(a,b)<0)
		printf("Amalnath comes first\n");
	else
		printf("Amarnath comes first\n");
}


