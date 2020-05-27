#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
struct node
{
	int x;
	int y;
	int step;
}a;
queue<node> q;
char mp[150][150];
int jud[150][150][100];   //只有该地判断值为0时才能走 (第三项为时间%k) 
int n,m,k,sx,sy,t,i,j,ans;
void writ(int b,int c,int d)
{
	a.x=b;
	a.y=c;
	a.step=d;
}
bool check(int nx,int ny,int ti)
{
	if(nx<1||nx>n||ny<1||ny>m)
	    return true;
	if(mp[nx][ny]=='#'||jud[nx][ny][ti%k]==1)
	    return true;
	if(mp[nx][ny]=='*'&&(ti%k!=0))
	    return true;
	return false;
}
int main()
{
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>mp[i][j];
				if(mp[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
			}
			getchar();
		}
		ans=9999999; 
		memset(jud,0,sizeof(jud));
		while(!q.empty())
		    q.pop();
		writ(sx,sy,0);
		q.push(a);
		jud[sx][sy][0]=1;//起点在0时刻不能走 
		while(1)
		{
			node temp=q.front();
			q.pop();
			if(mp[temp.x][temp.y]=='E')
			{
				ans=temp.step;
				break;
			}
			else
			    for(i=0;i<4;i++)
			    {
			    	int nextx=temp.x+dx[i],nexty=temp.y+dy[i],tim=temp.step+1;
			    	if(check(nextx,nexty,tim))
			    	    continue;
			    	writ(nextx,nexty,tim);
					q.push(a);
					jud[nextx][nexty][tim%k]=1;
				}
			if(q.empty())
			    break;
		}
		if(ans==9999999)
		    cout<<"-1"<<endl;
		else
		    cout<<ans<<endl;
	}
}
