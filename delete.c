#include <stdio.h>
#include <stdlib.h>
#define Max 10
typedef int DataType;
typedef struct
{
    DataType Arr[Max];
    DataType Length;
}List,*PList;
void creation(PList L)
{
    if(L==NULL)
    {
        return ;
    }
    L->Length=0;
}
void input(PList L)
{
    DataType i;
    for(i=0;i<Max;i++)
    {
        L->Arr[i]=i+1;
        L->Length++;
    }
}
void Delete(PList L , DataType i)
{
    if(i<1||i>L->Length)
    {
        printf("error");
        return -1;
    }
    else if(i==L->Length)
    {
        L->Length--;
    }
    else
    {
        DataType k;
        for(k=i;k<L->Length;k++)
        L->Arr[k-1]=L->Arr[k];
        L->Length--;
    }
}
void main()
{
    List L;
    DataType k,j;
    creation(&L);
    input(&L);
    printf("The original Arr:\n");
    for(j=0;j<L.Length;j++)
    {
        printf("%d\t",L.Arr[j]);
    }
    printf("\nPlease input the Kth to delete\n");
    scanf("%d",&k);
    Delete(&L,k);
    printf("The new Arr :\n");
    for(j=0;j<L.Length;j++)
    {
        printf("%d\t",L.Arr[j]);
    }
}
