#include<stdio.h>
struct euclidian
{
	float distance;
}dis1,dis2;

void main()
{
	float sum=0;
	printf("Enter the distance between first two points : ");
	scanf("%f",&dis1.distance);
	printf("Enter the distance between another two points : ");
	scanf("%f",&dis2.distance);
	sum=dis1.distance+dis2.distance;
	printf("\nTotal distance = %f\n",sum);
}
