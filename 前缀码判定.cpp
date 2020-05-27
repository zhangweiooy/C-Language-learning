#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct BiTNode
{
	int flag;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
char str[100000];
int judge=0;
void Code(BiTree bt)
{
	int len=strlen(str);
	BiTree road=bt;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='0')
		{
			if(road->lchild!=NULL)
			{
				road=road->lchild;
				if(road->flag==1||i==len-1)
				{
					judge=1;
					return;
				}
			}
			else
			{
				BiTree s;
				s=(BiTNode *)malloc(sizeof(BiTNode));
				s->lchild=s->rchild=NULL;
				if(i==len-1)
				    s->flag=1; 
				else
				    s->flag=0;
				road->lchild=s;
				road=road->lchild; 
			}
		}
		else
		{
			if(road->rchild!=NULL)
			{
				road=road->rchild;
				if(road->flag==1||i==len-1)
				{
					judge=1;
					return;
				}    
			}
			else
			{
				BiTree s;
				s=(BiTNode *)malloc(sizeof(BiTNode));
				s->lchild=s->rchild=NULL;
				if(i==len-1)
				    s->flag=1;
				else
				    s->flag=0;
				road->rchild=s;
				road=road->rchild;
			}
		}
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	BiTree bt;
	bt=(BiTNode *)malloc(sizeof(BiTNode));
	bt->flag=0;bt->lchild=NULL;bt->rchild=NULL;
	while(N--)
	{
		scanf("%s",str);
		Code(bt);
		if(judge==1)
		    break;
	}
	if(judge==0)
	    printf("YES\n");
	else
	    printf("%s\n",str);
}
