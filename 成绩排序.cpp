#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int t,n,i,j,max;
typedef struct m
{
	int a,b;
	char str[20];
}p;
p s[10000],temp;
int cmp(const void*c,const void*d)
{
	p *e=(p *)c;
	p *f=(p *)d;
	if(e->a==f->a)
	{
		if(e->b==f->b)
		{
			return strcmp(e->str,f->str);
		}
		else
		    return f->b-e->b;
	}
	else
	    return f->a-e->a;
}
int main()
{
	
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n); 
	    for(i=0;i<n;i++)
	    {
	    	scanf("%d %d %s",&s[i].a,&s[i].b,s[i].str);
		}
		qsort(s,n,sizeof(s[0]),cmp);
		
		for(i=0;i<n;i++)
		    printf("%s ",s[i].str);
		printf("\n");
	}
	return 0; 
}
