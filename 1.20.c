#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,n,temp,x,i;                  //频度 1；
    scanf("%d",&n);                     //频度 1；（输入多项式最高次数）
    scanf("%d",&x);                     //频度 1；（输入多项式的自变量）
    a=(int*)malloc(n*sizeof(int));      //频度 1；
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);              //频度 n;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);              //频度 n；
    }
    temp=a[n-1];                        //频度 1；
    for(i=n-1;i>0;i--)
    {
       temp=temp*x+a[i-1];              //频度 n-1；
    }
    free(a);                            //频度 1；
    printf("%d",temp);                  //频度 1；
}                                       //整个程序的复杂度为O(n);
