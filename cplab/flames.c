#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int t,j,strlen1,strlen2=0,count1=0,count2=0,x_rem;
	char *names[30],name2[15],temp1[15],temp2[15],flame[]="FLAME",temp;

	printf("Enter the no. of testcases\n");
	scanf("%d",&t);
	printf("Enter the names in lowercase separated by a space\n");
	for(int i=0;i<=t;i++)
	{
		names[i]=malloc(30*sizeof(char));
		fgets(names[i],30,stdin);
	}

	for(int i=1;i<=t;i++)
	{
		strlen1=strlen(names[i]);
		for(j=0;j<strlen1;j++)
		{
			if(names[i][j]==' ')
			{
				for(int l=j+1,k=0;l<strlen1;l++,k++)
				{
					name2[k]=names[i][l];
					temp2[k]=name2[k];
					strlen2++;
				}
				strlen2--;
				break;
			}
			temp1[j]=names[i][j];
		}

		for(int m=0;m<j;m++)
			for(int n=0;n<strlen2;n++)
				if(names[i][m]==name2[n])
				{
					temp1[m]='$';
					temp2[n]='$';
				}

		for(int m=0;m<j;m++)
		{
			if(temp1[m]!='$')
				count1++;
		}
		for(int n=0;n<strlen2;n++)
		{
			if(temp2[n]!='$')
				count2++;
		}
		
		x_rem=count1+count2;

		if(x_rem%5==1)
		{
			flame[0]='L';
			flame[1]='F';
			puts(flame);
		}
		else if(x_rem%5==2)
			puts(flame);
		else if(x_rem%5==0)
		{
			strcpy(flame,"FAMEL");
			puts(flame);
		}
		else
		{
			for(int m=1;m<=(x_rem%5)-2;m++)
			{
				temp=flame[m];
				flame[m]=flame[m+1];
				flame[m+1]=temp;
			}
			puts(flame);
		}

		strcpy(flame,"FLAME");
		count1=0;
		count2=0;
		strlen2=0;
	}
}
