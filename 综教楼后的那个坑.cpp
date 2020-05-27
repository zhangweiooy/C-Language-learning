#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
typedef long long ll;
typedef struct Node
{
	struct Node *prior;
	struct Node *next;
	int w,h;
	ll *time;
 }node;
 void sub(node* &p)
 {
 	ll sum=0;
 	while(p->prior->h!=p->next->h)
 	{
 		*(p->time)=sum+p->w;  //被覆盖的时间 
 		if(p->prior->h<p->next->h)
 		{
 			sum+=(p->prior->h - p->h)*(p->w);
 			p->prior->w+=p->w;
 			p->next->prior=p->prior;
 			p->prior->next=p->next;
 			p=p->prior;
		 }
		else
		{
			sum+=(p->next->h - p->h)*(p->w);
 			p->next->w+=p->w;
 			p->next->prior=p->prior;
 			p->prior->next=p->next;
 			p=p->next;
		}
		if(p->prior->h>p->h&&p->next->h>p->h)
		    continue;
		if(p->prior->h>p->h)
		    while(p->h>p->next->h)
		        p=p->next;
		if(p->next->h>p->h)
		    while(p->h>p->prior->h)
		        p=p->prior;
	 }
	*(p->time)=sum+p->w;
	return ;
 }
 int main()
 {
 	int n,i,wt,ht;
 	node *L,*p,*q,*low;
 	ll *time;
 	
 	scanf("%d",&n);
 	L=(node *)malloc(sizeof(node));
 	L->h=1000000;
 	L->prior=NULL;
 	L->next=NULL;
 	L->w=0;
 	L->time=NULL;
	q=low=L;
	time=(ll *)malloc(n*sizeof(ll));
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&wt,&ht);
		p=(node *)malloc(sizeof(node));
		p->w=wt;
		p->h=ht;
		p->time=time+i;
		q->next=p;
		p->prior=q;
		q=p;
		if(p->h<low->h)
		    low=p;
	}
	p=(node *)malloc(sizeof(node));
	p->h=1000000;
	p->w=0;
	p->time=NULL;
	q->next=p;
	p->prior=q;
	p->next=NULL;
	sub(low);
	while(n--)
	    printf("%lld\n",*(time++));
	return 0;
  } 
