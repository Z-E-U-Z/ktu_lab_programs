#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int j,t,n,p,k,test[105][3],arr[105][105],temp,num=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d %d",&test[i][0],&test[i][1],&test[i][2]);
        arr[i][0]=1;
        arr[i][1]=0;
        j=1;
        while(1)
        {
            arr[i][j]=arr[i][j-1]+test[i][1];
            num++;
            if(arr[i][j]>test[i][0])
                arr[i][j]-=test[i][0];
            j++;
            if(arr[i][j-1]==1)
                break;
        }
        
        for(int j=0;j<(num-1);j++)
        {
            for(int k=0;k<(num-j);k++)
                if(arr[i][k]>arr[i][k+1])
                {
                    temp=arr[i][k];
                    arr[i][k]=arr[i][k+1];
                    arr[i][k+1]=temp;
                }
        }
        num=0;
    }
    for(int i=0;i<t;i++)
        printf("%d\n",arr[i][test[i][2]]);

    return 0;
}

