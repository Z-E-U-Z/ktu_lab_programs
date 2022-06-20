#include<stdio.h>
void main()
{
	float a,b,c,d,e,f,g;
	float result;
	printf("Enter the values of a,b,c,d,e,f and g respectively\n");
	scanf("%f%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f,&g);
	result=((a-b/c*d+e)*(f+g));
	printf("THE RESULT IS %f",result);
}

