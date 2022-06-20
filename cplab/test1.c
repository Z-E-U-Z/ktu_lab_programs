#include <stdio.h>
void fun(void)
{
    auto int a=0;
    static int b=0;
    printf("a=%d,b=%d\n",a,b);
    a++;
    b++;
}

void main()
{
    int loop;
    for(loop=0; loop<5; loop++)
        fun();
    printf("%d",b);
}
