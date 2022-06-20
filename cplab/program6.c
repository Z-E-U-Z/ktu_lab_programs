#include<stdio.h>
void main()
{
	int i,n,a[100],temp;
	
	printf("Enter the no. of integers\n");
	scanf("%d",&n);
	
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	for(int j=n-1;j>0;j--)
	{
		for(i=0;i<j;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	
	printf("The elements in ascending order are\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
