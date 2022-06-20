#include<stdio.h>
void main()
{
	char a[50];
	int cons=0,vow=0,sp=0,spec=0;
	printf("Enter an sentence ending with $ symbol\n");
	gets(a);
	for(int i=0;i<50;i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
			vow++;
		else if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
			cons++;
		else if(a[i]==' ')
			sp++;
		else if(a[i]!='$')
			spec++;
		else if(a[i]=='$')
			break;
	}
	if(spec==0)
		printf("CONSONANTS=%d\nVOWELS=%d\nSPACES=%d\n",cons,vow,sp);
	else
		printf("Digits and special characters not allowed\n");	
}
