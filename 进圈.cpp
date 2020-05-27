#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
struct node
{
	int x;
	int y;
	int time;
}a;
void writ(int b,int c,int d)
{
	a.x=b;
	a.y=c;
	a.time=d;
}
char mp[1050][1050];
int jud[1050][1050];
queue<node> q;
int main()
{
	int n,m,k,i,j,sx,sy,ex,ey,ans=9999999;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	    for(j=1;j<=m;j++)
	        cin>>mp[i][j];
	cin>>sx>>sy>>ex>>ey;
	memset(jud,0,sizeof(jud));
	while(!q.empty())
	    q.pop();
	mp[sx][sy]='S';
	mp[ex][ey]='E';
	jud[sx][sy]=1;
	writ(sx,sy,0);
	q.push(a); 
	while(1)
	{
		node temp=q.front();
		q.pop();
		if(mp[temp.x][temp.y]=='E')
		{
			ans=temp.time;
			break;
		}
		else
		{
			for(i=0;i<4;i++)
			{
				for(j=1;j<=k;j++)
				{
					int nextx=temp.x+dx[i]*j,nexty=temp.y+dy[i]*j,tim=temp.time+1;
					if(nextx<1||nexty<1||nextx>n||nexty>m||jud[nextx][nexty]==1)
					    continue;
					if(mp[nextx][nexty]=='#')
					    break;
					if(mp[nextx][nexty]=='E')
		            {
		                ans=tim;
			            goto fuck;
		            }
					writ(nextx,nexty,tim);
					q.push(a);
					jud[nextx][nexty]=1;
				}
			}
		}
		if(q.empty())
		    break;
	}
	fuck: ;
	if(ans==9999999)
	    cout<<"-1"<<endl;
	else
	    cout<<ans<<endl;
}
