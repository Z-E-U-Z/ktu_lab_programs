#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned int t,m;
    long long int arr[10]={0,0,0,0,0,0,0,0,0,0};
    scanf("%u",&t);
    
    for(int i=0;i<t;i++)
    {
        scanf("%u",&m);
        for(int j=1;j<=m;j++)
        {
            arr[i]+=(((2*j)-1)%1000000007);
        }
    }
    for(int i=0;i<t;i++)
        printf("%lld\n",arr[i]);
    return 0;
}

