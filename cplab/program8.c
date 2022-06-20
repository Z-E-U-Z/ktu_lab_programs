#include<stdio.h>
void main()
{
	char a[60],b[30];
	int i,j,la,lb;
	printf("Enter first word ending with $ symbol\n");
	scanf("%s",a);
	printf("Enter second word ending with $ symbol\n");
	scanf("%s",b);

	for(i=0;i<60;i++)
	{
		if(a[i]=='$')
			break;
		else
			la++;
	}
        for(i=0;i<30;i++)
        {
                if(b[i]=='$')
                        break;
                else
                        lb++;
        }
	for(i=la+1,j=0;i<60&&j<=lb+1;i++,j++)
	{
		a[i]=b[j];
	}
	printf("After concatenation: %s\n",a);
}




