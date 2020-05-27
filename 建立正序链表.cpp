#include "stdio.h"  
#include "stdlib.h"  
  
struct node  
{   int data;  
    struct node * next;  
} ;  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
  
void outlist( PNODE );  
void  ins_list(PNODE,int);
  
int main ( )  
{       int num=1;  
    PNODE head;  
  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
            ins_list( head, num);  
    }  
  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}  
 
void ins_list( PNODE h, int num ) 
{
    PNODE r,p;
    r=h;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    p=(PNODE)malloc(sizeof(NODE));
    p->data=num;
    p->next=NULL;         //pÎª´ý²å½áµã
    if(h->next==NULL)
    { 
        h->next=p;
        r=p;
    }
    else
    {
        r->next=p;
        r=p;
    }
} 
 
