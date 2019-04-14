
#include <stdio.h>
#include <stdlib.h>
#define stacksize 100
int n,num=0;
typedef struct stack
{
    int top;
    int Arr[stacksize];
}Stack,*pStack;
Stack S;
void Init()
{
    S.top=-1;
}
void push(int e)
{
    S.top++;
    S.Arr[S.top]=e;
}
void pop()
{
    S.Arr[S.top]=0;
    S.top--;
}
int empty()
{
    if(S.top==-1) return 1;
    else return 0;
}
int Gettop()
{
    if(S.top!=-1)
    return S.Arr[S.top];
    else return 0;
}
void possible(int pos,int Order[],int step)
{
    if(pos <= n)
    {
        push(pos);
        possible(pos+1,Order,step);
        pop();
    }
    if(!empty())
    {
        int i=Gettop();
        pop();
        Order[step]=i;
        possible(pos,Order,step+1);
        push(i);
    }
    if(pos>n&&empty()==1)
    {
        for(int k=0;k<n;k++)
        {
            printf("%4d",Order[k]);
        }
        printf("\n");
        num++;
    }
}
void main()
{
    printf("Input the number of trains\n");
    scanf("%d",&n);
    int Order[stacksize];
    int cnt=0;
    Init();
    possible(1,Order,0);
    printf("It has %d results",num);
}
