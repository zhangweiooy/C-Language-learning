#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,map[205][205],s,t,dis[205],mark[205];
void dijkstra()
{
	int i,j;
	memset(dis,inf,sizeof(dis));
	dis[s]=0;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
	{
		int min=inf,k;
		for(j=0;j<n;j++)
		{
			if(!mark[j]&&dis[j]<min)
			{
				min=dis[j];
				k=j;
			}
		}
		if(min==inf)
		    break;
		mark[k]=1;
		for(j=0;j<n;j++)
		{
			if(map[k][j]<inf&&!mark[j]&&dis[j]>dis[k]+map[k][j])
			    dis[j]=dis[k]+map[k][j];
		}
	}
	return ;
}
int main()
{
	int a,b,x,i,j;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(map,inf,sizeof(map));
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>x;
			if(map[a][b]>x)
			    map[a][b]=map[b][a]=x;
		}
		cin>>s>>t;
		dijkstra();
		if(dis[t]==dis[204])
		    cout<<"-1"<<endl;
		else
		    cout<<dis[t]<<endl;
	}
	return 0;
}
