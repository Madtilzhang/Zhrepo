#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,n,temp,x,i;                  //Ƶ�� 1��
    scanf("%d",&n);                     //Ƶ�� 1�����������ʽ��ߴ�����
    scanf("%d",&x);                     //Ƶ�� 1�����������ʽ���Ա�����
    a=(int*)malloc(n*sizeof(int));      //Ƶ�� 1��
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);              //Ƶ�� n;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);              //Ƶ�� n��
    }
    temp=a[n-1];                        //Ƶ�� 1��
    for(i=n-1;i>0;i--)
    {
       temp=temp*x+a[i-1];              //Ƶ�� n-1��
    }
    free(a);                            //Ƶ�� 1��
    printf("%d",temp);                  //Ƶ�� 1��
}                                       //��������ĸ��Ӷ�ΪO(n);
