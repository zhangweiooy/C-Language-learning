#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int parent[1002],n,m;
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
	int i,j,x,y;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		    break;
		scanf("%d",&m);
		for(i=0;i<1002;i++)
		    parent[i]=i;
		for(i=1;i<=m;i++)
		{   
		    scanf("%d %d",&x,&y);
		    join(x,y);
		}
		int count=0;
		for(i=1;i<=n;i++)
		    if(find(i)==i)
		        count++;
		printf("%d\n",count-1);
	}
	return 0;
}
