#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
#define inf 0x3f3f3f3f
int n,parent[10005];
struct road
{
	int from,to,value;
	bool operator < (road other)
	{
		return value < other.value;
	}
}q[5005];
int find(int x)
{
	if(x==parent[x])
	    return x;
	else return x=find(parent[x]);
}
void join(int x,int y)
{
	parent[find(x)]=find(y);
}
int main()
{
	int i,j;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		    break ;
		int m=n*(n-1)/2;
		for(i=0;i<10005;i++)
		    parent[i]=i;
		for(i=1;i<=m;i++)
			scanf("%d %d %d",&q[i].from,&q[i].to,&q[i].value);
		sort(q,q+m+1);
		int ans=0;
		for(i=1;i<=m;i++)
		{
			if(find(q[i].from)==find(q[i].to))
			    continue;
			ans+=q[i].value;
			join(q[i].from,q[i].to);
		}
		printf("%d\n",ans);
	}
}
