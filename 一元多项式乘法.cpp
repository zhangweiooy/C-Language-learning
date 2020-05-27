#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void multiplication( NODE * head1, NODE * head2, NODE * head3)
{
	NODE * p1,* p2, * p3;
	p1=head1;
	while(p1->next)
	{
		NODE * p4,* p;
		p4=( NODE * ) malloc( sizeof(NODE) );
		p4->next=NULL;
		p2=head2;p3=head3;p=p4;
		while(p2->next)
		{
			NODE * q;
			q=( NODE * ) malloc( sizeof(NODE) );
			q->next=NULL;
			q->coef=p1->next->coef * p2->next->coef;
			q->exp=p1->next->exp + p2->next->exp;
			if(q->coef!=0)
			{
				p->next=q;
			    p=p->next;
			}
			p2=p2->next;
		}
		NODE * q1;
		while(p3->next&&p4->next)
	    { 
	        if(p3->next->exp>p4->next->exp) 
		    {
		    	q1=p4->next;
		    	p4->next=q1->next;
		    	q1->next=p3->next;
		    	p3->next=q1;
		    }
		    else if(p3->next->exp==p4->next->exp)  
		    {
		    	p3->next->coef+=p4->next->coef;
		    	if(p3->next->coef==0)
		    	{
		    		q1=p3->next;
		    		p3->next=q1->next;
		    		free(q1);
		    	}
		    	q1=p4->next;
		    	p4->next=q1->next;
		    	free(q1);
		    }
		    else if(p3->next->exp<p4->next->exp)
		        p3=p3->next;
	    }
	    if(p4->next)    
	    	p3->next=p4->next;
		p1=p1->next;
	} 
	if(head3->next==NULL)
	{
		head3->next=( NODE * ) malloc( sizeof(NODE) );
		head3->next->coef=0;
		head3->next->exp=0;
		head3->next->next=NULL;
	}
}

void input( NODE * head )
{   int flag, sign, sum, x;
	char c;

    NODE * p = head;

	while ( (c=getchar()) !='\n' )
	{
		if ( c == '<' )
	    {    sum = 0;
	         sign = 1;
	         flag = 1;
        }
		else if ( c =='-' )
             sign = -1;
		else if( c >='0'&& c <='9' )
		{    sum = sum*10 + c - '0';
        }
		else if ( c == ',' )
        {    if ( flag == 1 )
             {    x = sign * sum;
                  sum = 0;
                  flag = 2;
		          sign = 1;
             }
        }
		else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
             p->next->coef = x;
             p->next->exp  = sign * sum;
             p = p->next;
             p->next = NULL;
             flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );
    
    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );
    
	head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

	output( head3 );
	return 0;
}


