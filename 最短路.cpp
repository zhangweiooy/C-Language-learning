#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,map[105][105],dis[105],mark[105];
void dijkstra()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		int min=inf,k;   
		for(j=1;j<=n;j++)
		    if(!mark[j]&&dis[j]<min)
		    {
		    	min=dis[j];
		    	k=j;
			}
		if(min==inf)
		    break;
		mark[k]=1;
		for(j=1;j<=n;j++)
		{                             //mmp此点要注意 
			if(map[k][j]<inf&&dis[j]>dis[k]+map[k][j]) //若能走，则尝试松弛距离 
			    dis[j]=dis[k]+map[k][j];
		}
	}
	return ;
}
int main()
{
	int i,j,a,b,c;
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0)
		    break;
		memset(map,inf,sizeof(map));
		for(i=1;i<=m;i++)
		{
			cin>>a>>b>>c;
			map[a][b]=c;
			map[b][a]=c;
		}
		memset(mark,0,sizeof(mark));
		memset(dis,inf,sizeof(dis));
		dis[1]=0;
		dijkstra();
		cout<<dis[n]<<endl;
	}
	return 0;
}
