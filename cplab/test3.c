#include <stdio.h>
void main()
{
	struct person
	{
		char x,y,z;
	};
	struct person per1={'a','b','c'};
	struct person *p;
	p=&per1;
	printf("%p\t", p); //memory location of structure pointer
	printf("%c %c %c", *((char*)p), *((char*)p+1), *((char*)p+2)); //type conversion
	printf("\t%p", p); //type conversion occurs only inside the print statement
}
	
