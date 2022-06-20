#include<stdio.h>
int add(int arr[],int n)
{
	int sum=0,*ptr=arr;
        for(int i=0;i<n;i++)
        {
        	sum+=*ptr;
        	ptr++;
        }
        return sum;
}
void main()
{
        int arr[50],*ptr,n;
        ptr=arr;
        printf("Enter the no. of elements\n");
        scanf("%d",&n);
        printf("Enter the elements\n");
        for(int i=0;i<n;i++)
        {
                scanf("%d",ptr);
                ptr++;
        }
        printf("The sum of the elements are %d\n",add(arr,n));
}
        	
