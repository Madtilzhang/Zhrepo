
#include<stdio.h>
#include<stdlib.h>
#define N_LEAVE 26
#define N_NODE  (26*2-1)
typedef struct _Node
{
	char character;
	int weight;
	int lchild;
	int rchild;
	int parent;
}Node,*pNode;
typedef struct _Code
{
	int HufCode[N_LEAVE];
	int  Start;
	char Char;
}Code,*pCode;
void Huffman(Node Ht[],int Wt[])
{
	int i,j,x1,x2;
	int min1,min2;
	for(i=0;i<N_NODE;i++)
	{
		Ht[i].parent = -1;
		Ht[i].lchild = -1;
		Ht[i].rchild = -1;
		if(i<N_LEAVE)
		{
			Ht[i].weight = Wt[i];
			Ht[i].character = i+65;
		}
		else
		{
			Ht[i].weight = 0;
			Ht[i].character = '?';
		}
	}
	for(i=1;i<=N_LEAVE-1;i++)
	{
		min1 = min2 = 1000;
		x1 = x2 = 0;
		for(j=0;j<N_LEAVE-1+i;j++)
		{
			if(Ht[j].parent == -1 && Ht[j].weight<min1 )
			{
				min2 = min1;
				x2 = x1;
				min1 = Ht[j].weight;
				x1 = j;
			}
			else
			{
				if( Ht[j].parent == -1 && Ht[j].weight<min2 )
				{
					min2 = Ht[j].weight;
					x2 = j;
				}
			}
		}
		Ht[x1].parent = N_LEAVE-1+i;
		Ht[x2].parent = N_LEAVE-1+i;
		Ht[N_LEAVE-1+i].weight = Ht[x1].weight + Ht[x2].weight;
		Ht[N_LEAVE-1+i].lchild = x1;
		Ht[N_LEAVE-1+i].rchild = x2;
	}
}

void Code_Ht(Node Ht[],Code Hc[])
{
	int i,d,p,j;
	Code x;
	for(i=0;i<N_LEAVE;i++)
	{
		x.Char = Ht[i].character;
		x.Start = N_LEAVE-1;
		d = i;
		p = Ht[i].parent;
		while(1)
		{
			if(Ht[p].lchild == d)
				x.HufCode[x.Start] = 0;
			else if(Ht[p].rchild == d)
				x.HufCode[x.Start] = 1;
			else
				printf("ERROR!");
			d = p;
			p = Ht[d].parent;
			if(p == -1) break;
			x.Start--;
		}
		for(j=x.Start;j<=N_LEAVE-1;j++)
		{
			Hc[i].HufCode[j] = x.HufCode[j];
		}
		Hc[i].Start = x.Start;
		Hc[i].Char = x.Char;
	}
}



void PrintCode(Code Hc[])
{
	int i,j;
	for(i=0;i<N_LEAVE;i++)
	{
		for(j=Hc[i].Start;j<N_LEAVE;j++)
		{
			printf("%d",Hc[i].HufCode[j]);
		}
		printf("%5c\n",Hc[i].Char);
	}
}

void FindCode(Code Hc[],char s[])
{
	int i,j,k=0;
	printf("\n");
	printf("\n");
	while(s[k]!='\0'){

	for(i=0;i<N_LEAVE;i++)
	{
		if( s[k] == Hc[i].Char )
		{
			for(j=Hc[i].Start;j<N_LEAVE;j++)
			{
				printf("%d",Hc[i].HufCode[j]);
			}
		}
	}
	k++;
  }
}
void trans(char index[],Node hc[])
{
    int i,root,p;
    for(i=0;i<N_NODE;i++)
    {
        if(hc[i].parent==-1)
           {
               root=i;
               break;
           }
    }
    p=root;
    for(i=0;index[i]!='\0';i++)
    {
        if(index[i]=='1')
        {
            p=hc[p].rchild;
        }
        if(index[i]=='0')
        {
            p=hc[p].lchild;
        }
        if(hc[p].lchild==-1&&hc[p].rchild==-1)
        {
            printf("%c",hc[p].character);
            p=root;
        }
    }
}
int main()
{
	Node HufTree[N_NODE];
	Code HCode[N_LEAVE];
	int Wt[N_LEAVE] = {64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
	char s[]={"THISPROGRAMISMYFAVORITE"};
	Huffman(HufTree,Wt);
	Code_Ht(HufTree,HCode);
	PrintCode(HCode);
	FindCode(HCode,s);

	char string[20];
	scanf("%s",string);
	trans(string,HufTree);
}
