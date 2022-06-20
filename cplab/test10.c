#include<stdio.h>

struct str
{
	int a;
	int b;
};

int method(struct str* p)
{
	p->a = 2;
	p->b = 1;
}

void main()
{
	struct str *p;
	//struct str a; //Without this statement, segmentation fault occurs
	method(p);
	printf("%d\n", p->a);
}
