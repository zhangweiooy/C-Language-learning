#include"stdio.h"
#include"math.h"
#include"stdlib.h"
struct m
{
	long long cost;
	double v;
	double ep;     //µ¥¼Û 
}store[32];
int cmp(const void*e1,const void*e2)
{
	m *e=(m *)e1;
	m *f=(m *)e2;
	return e->ep-f->ep;
}
long long fun(long long left,long long num,long long ans)
{
	long long count;
	count=left/store[num].v;
	ans+=count*store[num].cost;
	left-=count*store[num].v;
	if(left==0)
	    return ans;
	else
	{
		if(fun(left,num+1,ans)>=ans+store[num].cost)
		    return ans+store[num].cost;
		else
		    return fun(left,num+1,ans);
	}
}
int main()
{
	long long n,l,i;
	scanf("%lld %lld",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&store[i].cost);
		store[i].v=pow(2,i);
		store[i].ep=store[i].cost/store[i].v;
	}
	qsort(store,n,sizeof(store[0]),cmp);
	printf("%lld\n",fun(l,0,0));
	return 0;
}
