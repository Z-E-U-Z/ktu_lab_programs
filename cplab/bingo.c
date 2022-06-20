#include<stdio.h>
#include<stdlib.h>
void main()
{
	printf("\t\t\t\t\t\t\t\t\t\t     WELCOME TO BINGO !\n\n\n\n\n");
	char n;

l1:
	printf("\v\t\t\t\t\t\t\t\t\t\t   To play BINGO, enter Y\n\n\t\t\t\t\t\t\t\t\t\tTo EXIT, enter ANY other key\n");
	scanf("\n%c",&n);
	if(n!='Y' && n!='y')
	{
l2:
			printf("\nAre you sure you want to exit ? [Y/N]\n");
			scanf("\n%c",&n);
			if(n=='Y'||n=='y')
				exit(0);
			else if(n=='N'||n=='n')
				goto l1;
			else
			{
				printf("Enter valid input\n");
				goto l2;
			}
	}
	else
		printf("\n\t\t\t\t\t\t\t     NOTE: Make sure that bingo.c file is run in all the players' devices\n\n");


	int bingo[5][5];
l6:
	printf("\n\t\t\t\t\t\t        Enter the numbers(1-25) of your matrix (If the numbers are repeated enter 404)\n");
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
l3:			
			scanf("\n%d",&bingo[i][j]);
			if(bingo[i][j]==404)
			{
				if(j==0)
				{
					bingo[i][j]=1;
					i--;
					j=4;
					printf("Enter from the repeated number\n");
					goto l3;
				}
				else
				{
					bingo[i][j]=1;
					j--;
					printf("Enter from the repeated number\n");
					goto l3;
				}
			}
			else if(bingo[i][j]<1 || bingo[i][j]>25)
			{
				printf("Please enter numbers from 1-25\n");
				goto l3;
			}
		}
	}
	printf("\nThe entered matrix is\n");
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			if(bingo[i][j]>0 && bingo[i][j]<10)
				printf("%d  ",bingo[i][j]);
			else
				printf("%d ",bingo[i][j]);
		printf("\n");
	}
	int flag,bingosum=0,num,i,j,count;

	while(1)
	{
l5:
		bingosum=0;
l9:
		printf("\nEnter the strike-off number\n");
l4:
		scanf("\n%d",&num);
		if(num<1 || num>25)
		{
			printf("Please enter a number from 1-25\n");
			goto l4;
		}

		count=0;

		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(num==bingo[i][j])
				{
					bingo[i][j]=0;
					printf("The matrix becomes\n");
					for(int m=0;m<5;m++)
					{
						for(int n=0;n<5;n++)
						{
							if(bingo[m][n]>=0 && bingo[m][n]<10)
								printf("%d  ",bingo[m][n]);
							else
								printf("%d ",bingo[m][n]);
						}
						printf("\n");
					}
					goto l8;
				}
				count++;
			}
		}

                if(count==25)
                {
			printf("Number already striked off! Please enter another number from 1-25\n");
                        goto l4;
                } 
		
l8:
		for(i=0;i<5;i++)
		{
			flag=0;
			for(j=0;j<5;j++)
			{
				if(bingo[i][j]==0)
					flag++;
			}
			if(flag==5)
				bingosum++;
		}
		for(j=0;j<5;j++)
		{
			flag=0;
			for(i=0;i<5;i++)
			{
				if(bingo[i][j]==0)
					flag++;
			}
			if(flag==5)
				bingosum++;
		}
		flag=0;
		for(i=0;i<5;i++)
		{
			if(bingo[i][i]==0)
				flag++;
			if(flag==5)
				bingosum++;
		}
		flag=0;
		for(i=0;i<5;i++)
		{
			if(bingo[i][4-i]==0)
				flag++;
			if(flag==5)
				bingosum++;
		}
		switch(bingosum)
		{
			case 1:
				printf("\nB\n");
				break;
			case 2:
				printf("\nBI\n");
				break;
			case 3:
				printf("\nBIN\n");
				break;
			case 4:
				printf("\nBING\n");
				break;
		}
		if(bingosum>=5)
			break;
		goto l5;
	}
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tBINGO!\n");
	printf("\n\nEnter T for TIE-breaker\n\nEnter any other key to continue\n");
	scanf("\n%c",&n);
	if(n=='t' || n=='T')
	{
		if(bingosum<10)
			bingosum=-(1+(bingosum%5));
		else if(bingosum==10)
			bingosum=-6;
		else if(bingosum==12)
			bingosum=-8;
		goto l9;
	}

l7:
	printf("\n\n\nDo you want to play again? [Y/N]\n");
	scanf("\n%c",&n);
	if(n=='N'||n=='n')
		exit(0);
	else if(n=='Y'||n=='y')
		goto l6;
	else
	{
		printf("Enter valid input\n");
		goto l7;
	}
}
