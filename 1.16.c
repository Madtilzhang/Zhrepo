#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,Y,Z,temp;
    printf("Please input 3 numbers");
    scanf("%d",&X);
    scanf("%d",&Y);
    scanf("%d",&Z);
    if(X<Y)   {temp=X;   X=Y;     Y=temp;};
    if(X<Z)   {temp=X;   X=Z;     Z=temp;};
    if(Y<Z)   {temp=Y;   Y=Z;     Z=temp;};
    printf("%d   %d   %d",X,Y,Z);
}
