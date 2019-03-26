#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int code;
    int num;
    struct Node* next;
}Node,*PNode;

PNode CreateNode(int n)
{
    PNode head=NULL,p=NULL,q;
    for(int i=1;i<=n;i++)
    {
         PNode p=(Node*)malloc(sizeof(Node));
         printf("Input the %d code\t",i);
         scanf("%d",&p->code);
         p->num=i;
        if(i==1)
        {
            q=p;
            head=q;
        }
        if(i>1&&i<n)
        {
            q->next=p;
            q=p;
        }
        if(i==n)
        {
            q->next=p;
            p->next=head;
        }
    }
    return head;
}
int Joseph(PNode head,int m,int n)
{
    PNode p=head;
    int i=1,k=m,j=n;
    while(j>0)
    {
        if(p->next==p)
        {
            printf("%d\t",p->num);
            return 0;
        }
        if(i==k)
        {
            PNode s=p;
            p=head;
            while(p->next!=s)   p=p->next;
            p->next=s->next;
            head=s->next;
            k=s->code;
            i=0;
            printf("%d\t",s->num);
            free(s);
            j--;
        }
        i++;
        p=p->next;
    }
}
void main()
{

    int m,n;
    printf("Input the number of persons\n");
    scanf("%d",&n);
    printf("Input the first code\n");
    scanf("%d",&m);
    PNode head=CreateNode(n);
    Joseph(head,m,n);

}
