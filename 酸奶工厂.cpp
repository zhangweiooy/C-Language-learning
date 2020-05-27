#include"stdio.h"
struct m
{
	long long cost;
	long long y;
	long long id;
}x[10005];
long long fun(long long n,long long s)
{
	long long ans=x[0].cost*x[0].y,i,temp=0,ago;
	for(i=1;i<n;i++)
	{
		ago=x[temp].cost*x[i].y+s*(i-x[temp].id)*x[i].y;
		if(ago<x[i].cost*x[i].y)
		{
			ans+=ago;
		}
		else
		{
			ans+=x[i].cost*x[i].y;
			temp=i;
		}
	}
	return ans;
}
int main()
{
	long long i,n,s;
	scanf("%lld %lld",&n,&s);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&x[i].cost,&x[i].y);
		x[i].id=i;
	}
	printf("%lld\n",fun(n,s));
	return 0;
}
