#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int parent[200005],n,m;
int find(int x)
{
	if(x==parent[x])
	    return x;
	else
	    return x=find(parent[x]);
}
void join(int x,int y)
{
	parent[find(x)]=find(y);
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		for(i=0;i<200005;i++)
		    parent[i]=i;
		while(n!=-1)
		{
			scanf("%d",&m);
			if(find(n)==find(m))
			    ans++;
			else
			    join(n,m);
			scanf("%d",&n);
		}
		printf("%d\n",ans);
	}
	return 0;
}
