#include<stdio.h>
#include<stdlib.h>
int n,k,m;
typedef struct node
{
	int data;
	struct node *prior;
	struct node *next;
 } node;
 void initLink(node* &h)
 {
 	node *p,*q;
 	int i;
 	h=(node *)malloc(sizeof(node *));
 	p=h,q=h;
 	for(i=1;i<=n;i++)
 	{
 		 p=(node *)malloc(sizeof(node *));
 		 p->data=i;
 		 p->prior=q;
 		 q->next=p;
 		 q=p;
	 }
	 p->next=h;
	 h->prior=p;
 }
 void Delete(node* &p)
 {
 	node *q=p->prior;
 	q->next=p->next;
 	q=p->next;
 	q->prior=p->prior;
 }
 int main()
 {
 	int i;
 	node *h,*l,*r,*left,*right;
 	scanf("%d,%d,%d",&n,&k,&m);
 	if(n<1||k<1||m<1)
    {
       printf("n,m,k must bigger than 0.\n");
       return 0;
    } 
    if(k>n)
    {
     	printf("k should not bigger than n.\n");
    	return 0;
    }
    initLink(h);
    r=h->next;
    while(r->data!=k)  //起点 
    {
    	r=r->next;
	}
	l=r;
	while(n)
	{
		right=r;
		left=l;
		for(i=1;i<m;i++)
		{
			right=right->next;
			left=left->prior;
			if(right==h)
			    right=right->next;
			if(left==h)
			    left=left->prior;   //头结点跳过去			    
		}
		r=right->next;
		l=left->prior;
		if(r==h)
		    r=r->next;
		if(l==h)
		    l=l->prior;
	    if(right!=left)
	    {
	    	n-=2;
	    	printf("%d-%d,",right->data,left->data);
	    	Delete(right);
	    	Delete(left);
		}
		else
		{
			n--;
			printf("%d,",right->data);
			Delete(right);
		}
	}
	printf("\n");
 }
