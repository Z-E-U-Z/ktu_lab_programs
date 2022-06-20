#include <stdio.h>
int counter = 0;
int calc(int a, int b)
{
	int c;
	counter++;
	if(b == 3) return(a*a*a);
	else
	{
		c = calc(a, b/3);
		return(c*c*c);
	}
}
int main()
{
	calc(4,81);
	printf("%d", counter);
}

