#include<stdio.h>
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
        printf("The array is given below:\n");
        ptr=arr;
        for(int i=0;i<n;i++)
        {
                printf("%d\n",*ptr);
                ptr++;
        }
}

	
