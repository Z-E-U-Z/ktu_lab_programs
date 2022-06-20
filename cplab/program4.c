#include<stdio.h>
void main()
{
	int i,arr[100],n,sum=0;
	float avg;
	printf("Enter the no. of integers\n");
	scanf("%d",&n);
	printf("Enter the integers\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		sum+=arr[i];
	avg=sum/n;
	printf("SUM = %d\nAVERAGE = %0.3f\n",sum,avg);
}


