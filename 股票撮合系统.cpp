#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct MyStruct
{
	int orderid;
	int stock;
	float price;
	int num;
	char type;
	struct MyStruct *next;
}node;
node *buy = NULL,*_buy=NULL,*_sell=NULL, *sell = NULL, *b, *s, *p, *q, *p1,*q1;
int stock, num, count = 1, orderid;
float price=0.0;
char type;
int min(int x,int y)
{
	if(x<=y)
	    return x;
	else
	    return y;
}
void subbuy()
{
	
	b=buy->next;
	s=sell->next;
	while (s != NULL)
	{
		if (price>=s->price)
		{
			if (stock==s->stock)
			{
				if(num==s->num)
				{
			    	printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",(price+s->price)/2, num, count-1, s->orderid);
			        num=0;
			        sell->next=s->next;
			        free(s);
			        s=sell->next;
			        break;
			    }
			    else if(num<s->num)
			    {
			    	printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (price + s->price) / 2, num, count - 1, s->orderid);
			        s->num-=num;
			        num=0;
			        break;
			    }
		    	else if(num>s->num)
		    	{
			    	printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (price + s->price) / 2, s->num,count- 1, s->orderid);
		    	    num-=s->num;
			        sell->next=s->next;
			        free(s);
		    	    s=sell->next;
		    	    continue;
		    	}
	    	}
	    	else
	    	{
	    		sell=sell->next;
	    		s=sell->next;
	    		continue;
			}
		}
		else
		    break;
	}
	if (num!=0)
    {
		q=buy;
		p=q->next;
		while (p!=NULL)
		{
			if (price>p->price)
			{
				node *np=(node*)malloc(sizeof(node));
				np->orderid=count-1;
				np->stock = stock;
		    	np->price = price;
		    	np->num = num;
		    	np->type = type;
		    	q->next=np;
				np->next=p;
				break;
			}
			else
			{
				q=q->next;
				p=q->next;
			}	
		}
		if(p==NULL)
		{
			node *np=(node*)malloc(sizeof(node));
			np->orderid=count-1;
			np->stock = stock;
		    np->price = price;
		    np->num = num;
		    np->type = type;
		    q->next=np;
			np->next=NULL;
		}
	}		
	return;	
}
void subsell()
{
	b=buy->next;
	s=sell->next;
	while (b != NULL)
	{
		if (price<=b->price)
		{
			if (stock==b->stock)
			{
				if(num==b->num)
				{
				    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",(price+b->price)/2, num, count-1, b->orderid);
			        num=0;
			        buy->next=b->next;
			        free(b);
			        b=buy->next;
			        break;
			    }
			    else if(num<b->num)
			    {
			    	printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (price+b->price)/2, num, count-1, b->orderid);
			        b->num-=num;
			        num=0;
			        break;
			    }
		    	else if(num>b->num)
		    	{
			    	printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (price+b->price)/2, b->num, count-1, b->orderid);
		    	    num-=b->num;
			        buy->next=b->next;
			        free(b);
		    	    b=buy->next;
		    	    continue;
		    	}
	    	}
	    	else
	    	{
	    		buy=buy->next;
	    		b=buy->next;
	    		continue;
			}
		}
		else
		    break;
	}
	if (num!=0)
    {
		q=sell;
		p=q->next;
		while (p!=NULL)
		{
			if (price< p->price)
			{
				node *np=(node*)malloc(sizeof(node));
				np->orderid=count-1;
				np->stock = stock;
		    	np->price = price;
		    	np->num = num;
		    	np->type = type;
		    	q->next=np;
				np->next=p;
				break;
			}
			else
			{
				q=q->next;
				p=q->next;
			}	
		}
		if(p==NULL)
		{
			node *np=(node*)malloc(sizeof(node));
			np->orderid=count-1;
				np->stock = stock;
		    	np->price = price;
		    	np->num = num;
		    	np->type = type;
		    	q->next=np;
				np->next=NULL;
		}
	}
	return;	
}
int main()
{
	_buy = (node*)malloc(sizeof(node));
	_sell = (node*)malloc(sizeof(node));
	_buy->next = NULL;
	_sell->next = NULL;
	int typ;
	while (1)
	{
		scanf("%d", &typ);
		if (typ == 0)
		{
			exit(0);
		}
		else if (typ == 1)
		{
			scanf("%d %f %d %c", &stock, &price, &num,&type);
			printf("orderid: %04d\n", count++);
			if (type=='b')
			{
				buy=_buy;
				sell=_sell;
				subbuy();
			}
			if (type == 's')
			{
				buy=_buy;
				sell=_sell;
				subsell();
			}
		}
		else if (typ == 2)
		{
			scanf("%d", &stock);
			printf("buy orders:\n");
			p = _buy;
			q=p->next;
			p1=_sell;
			q1=p1->next;
			while (q!=NULL)
			{
				if (q->stock == stock)
				{
					printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q->orderid, q->stock, q->price, q->num, q->type);
				}
				p = p->next;
				q=p->next;
			}
			printf("sell orders:\n");
			while (q1!=NULL)
			{
				if (q1->stock == stock)
				{
					printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",q1->orderid,q1->stock,q1->price,q1->num,q1->type);
				}
				p1 = p1->next;
				q1=p1->next;
			}
		}
		else if (typ == 3)
		{
			scanf("%d", &orderid);
			int flag1=0,flag2=0;
			p=_buy;
			q = p->next;
			p1=_sell;
			q1=p1->next;
			while (q&&flag1==0) 
            { 
                if (q->orderid == orderid) 
                { 
                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",q->orderid,q->stock,q->price,q->num,q->type); 
                    p->next = q->next; free(q); flag1 = 1; break; 
                } 
                else 
                { 
                p = p->next; q = p->next; 
                } 
           } 
           while (q1&&flag2==0&&flag1==0) 
           { 
               if (q1->orderid == orderid) 
               { 
                   printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q1->orderid, q1->stock, q1->price, q1->num, q1->type); 
                   p1->next = q1->next; free(q1); flag2 = 1; break; 
               } 
               else 
               { 
                   p1 = p1->next; q1 = p1->next; 
               } 
           } 
           if (flag1==0&&flag2==0) 
           { 
               printf("not found\n"); 
           } 
	    }
    }
	return 0;
}
