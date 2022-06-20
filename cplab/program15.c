#include<stdio.h>
void read(int a[][10],int m,int n)
{
	printf("Enter the array elements\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}
void display(int a[][10],int m,int n)
{
        for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
                        printf("%d\t",a[i][j]);
		printf("\n");
	}
}
int sum(int a[][10],int b[][10],int a1,int a2, int b1, int b2)
{
	if(a1==b1&&a2==b2)
	{
		for(int i=0;i<a1;i++)
			for(int j=0;j<a2;j++)
				a[i][j]+=b[i][j];
	}
	else
	{
		printf("MATRIX ADDITION NOT POSSIBLE\n");
		return 0;
	}
	printf("THE SUM IS\n");
}
int product(int a[][10],int b[][10],int c[][10],int a1,int a2,int b1,int b2)
{
	for(int i=0;i<a1;i++)
		for(int j=0;j<b2;j++)
			c[i][j]=0;
	if(a2==b1)
	{
		for(int i=0;i<a1;i++)
		{
			for(int j=0;j<b2;j++)
			{
				for(int k=0;k<b1;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
	}
	else 
	{
		printf("MATRIX MULTIPLICATION NOT POSSIBLE\n");
		return 0;
	}
	printf("THE PRODUCT IS\n");
}
int transpose(int a[][10],int m,int n)
{
	int temp;
	if(m==n)
	{
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}
	}	else
	{
		printf("MATRIX IS NOT SQUARE\n");
		return 0;
	}
	printf("THE TRANSPOSE IS\n");
}

void main()
{
	int a[10][10],b[10][10],c[10][10],a1,a2,b1,b2,q;
	printf("Which matrix operation do you want to perform ?\n");
	printf("1.Addition\t2.Multiplication\t3.Transpose\n");
	scanf("%d",&q);
	switch(q)
	{
		case 1:
			printf("Enter the no. of rows and columns in array 1\n");
			scanf("%d%d",&a1,&a2);
			read(a,a1,a2);
			printf("Enter the no. of rows and columns in array 2\n");
			scanf("%d%d",&b1,&b2);
			read(b,b1,b2);
			if(sum(a,b,a1,a2,b1,b2)!=0)
				display(a,a1,a2);
			break;
		case 2:
			printf("Enter the no. of rows and columns in array 1\n");
                        scanf("%d%d",&a1,&a2);
                        read(a,a1,a2);
                        printf("Enter the no. of rows and columns in array 2\n");
                        scanf("%d%d",&b1,&b2);
                        read(b,b1,b2);
			if(product(a,b,c,a1,a2,b1,b2)!=0)
				display(c,a1,b2);
			break;
		case 3:
			printf("Enter the no. of rows and columns\n");
			scanf("%d%d",&a1,&a2);
			read(a,a1,a2);
			if(transpose(a,a1,a2)!=0)
				display(a,a1,a1);
			break;
		default:
			printf("INVALID INPUT\n");
			break;
	}
}

