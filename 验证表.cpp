#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
using namespace std;
typedef struct Node
{
	int id;
	char name[30];
	struct Node *next;
}node;
int main()
{
	int n1,n2,i;
	node *l,*p,*q;
	l=(node *)malloc(sizeof(node));
	l->next=NULL;

	q=l;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		p=(node *)malloc(sizeof(node));
		scanf("%d%s",&p->id,p->name);
		q->next=p;
		p->next=NULL;
		q=p;
	}
	scanf("%d",&n2);
	if(n2==0)
	{
		printf("the LIST2 is NULL.\n");
		return 0;
	}
	int idtemp,flag1=n2,flag2=0;
	char nametemp[30];
	for(i=0;i<n2;i++)
	{
		scanf("%d%s",&idtemp,nametemp);
		q=l->next;
		flag2=0;
		while(q->next!=NULL)
		{
			if(q->id==idtemp&&strcmp(q->name,nametemp)==0)
			{
				flag1--;
				flag2=1;
			}
			q=q->next;
		}
		if(flag2==0)
		    printf("%d %s is not in LIST1.\n",idtemp,nametemp);
	}
	if(flag1==0)
	    printf("the records of LIST2 are all in the LIST1.\n");
	return 0;
}
