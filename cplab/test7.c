#include<stdio.h>
void main()
{
	int t;
	char str[10][20];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
//		fgets(str[i],20,stdin);
//		gets(str[i]);
		scanf("%s",str[i]);
		printf(str[i]);
	}
	printf(str[0]);
}
