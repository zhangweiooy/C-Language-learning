#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int number;
  struct node * next;
}node;
node * initLink(int n){
  node * head=(node*)malloc(sizeof(node));
  head->number=1;
  head->next=NULL;
  node * cyclic=head;
  for (int i=2; i<=n; i++) {
    node * body=(node*)malloc(sizeof(node));
    body->number=i;
    body->next=NULL; 
    cyclic->next=body;
    cyclic=cyclic->next;
  }
  cyclic->next=head;//首尾相连
  return head;
}
void findAndKillK(node * head,int k,int m)
{
  int flag=0,count=0;
  node * tail=head;
  while (tail->next!=head) 
  {
    tail=tail->next;
  }
  node * p=head;
  while (p->number!=k) 
  {
    tail=p;
    p=p->next;
  }
  while (p->next!=p) 
  {
    for (int i=1; i<m; i++) 
	{
      tail=p;
      p=p->next;
    }
    tail->next=p->next;//将p结点摘下来
    if(flag==0)
    {
        printf("%d",p->number);
        count++;
        flag=1;
	}
	else
	{
		if(count%10==0)
		{
			printf("\n");
			printf("%d",p->number);
		}
		else
		    printf(" %d",p->number);
		count++;
		flag=2;
	}
    free(p);
    p=tail->next;
  }
  if(flag==0)
  {
  	printf("%d\n",p->number);
  }
  else if(flag==1)
           printf(" %d\n",p->number);
        else 
        {
           if(count%10==0)
           {
               printf("\n");
               printf("%d\n",p->number);
		   }
		   else
               printf(" %d\n",p->number);
        }
  free(p);
}
int main() {
  int n,k,m;
  scanf("%d,%d,%d",&n,&k,&m);
  node * head=initLink(n);
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
  findAndKillK(head, k, m);
  return 0;
}
