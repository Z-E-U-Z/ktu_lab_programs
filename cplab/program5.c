#include<stdio.h>
void main()
{
	int a[100],x,n,i,flag=0;
	printf("Enter the no. of integers\n");
	scanf("%d",&n);
	printf("Enter the integers\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the search element\n");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			printf("The element is found at position %d\n",i+1);
			flag++;
		}
	}
	if(flag==0)
		printf("The element is not found\n");
}
