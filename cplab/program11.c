#include<stdio.h>
#include<string.h>

struct org
{
	char name[50];
	int id;
	float salary;
};

void main()
{
	struct org employee[100];
	int i,n;
	printf("\nEnter the no. of employees in the organization : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter employee %d name separated using \"_\": ",i+1);
		scanf("%s",employee[i].name);
		printf("\nEmployee id : ");
		scanf("%d",&employee[i].id);
		printf("\nSalary : ");
		scanf("%f",&employee[i].salary);
	}

	printf("\nEmployee information:\n\n");
	for(i=0;i<n;i++)
	{
		printf("Employee %d name : %s\nEmployee id : %d\nSalary : %.2f\n\n",i+1,employee[i].name,employee[i].id,employee[i].salary);
	}
} 
