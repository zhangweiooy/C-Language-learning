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
	int time;
}a;
queue<node> q;
char mp[1050][1050];
int jud[1050][1050];
int road[1050][1050][2];
int n,m,k,i,j;
void writ(int b,int c,int d)
{
	a.x=b;
	a.y=c;
	a.time=d;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{    for(j=1;j<=m;j++)
	    {
	    	cin>>mp[i][j];
		}	
	}
	int ans=9999999;
	memset(jud,0,sizeof(jud));
	memset(road,0,sizeof(road));
	while(!q.empty())
	    q.pop();
	int _a,_b,wx,wy,nx,ny,died=0;
	cin>>_a>>_b;
	for(i=1;i<=_a;i++)
	{
		cin>>wx>>wy;
		if(mp[wx][wy]=='#')
		    died++;
		else 
		    mp[wx][wy]='E';
	}
	wx=-1;
	wy=-1;
	for(i=1;i<=_b;i++)
	{
		cin>>nx>>ny;
		if(mp[nx][ny]!='#')
		{   if(mp[nx][ny]=='E')
		    {
		    	wx=nx;
		    	wy=ny;
		    }
		    else
		    {
		        mp[nx][ny]='S';
		        writ(nx,ny,0);
		        q.push(a);
		        jud[nx][ny]=1;
	    	}
	    }
	}
	if(died==_a)
	{
	    cout<<"Cruel game"<<endl;
	    return 0;
	}
	if(wx!=-1&&wy!=-1)
	{
		cout<<"0"<<endl<<wx<<" "<<wy<<endl;
		return 0;
	}
	int ta,tb;
	while(1)
	{
		node temp=q.front();
		q.pop();
		if(mp[temp.x][temp.y]=='E')
		{
			ans=temp.time;
			ta=temp.x;
			tb=temp.y;
			break;
		}
		else
		{
			for(i=0;i<4;i++)
			{
				int nextx=temp.x+dx[i],nexty=temp.y+dy[i],tim=temp.time+1;
				if(nextx<1||nexty<1||nextx>n||nexty>m||mp[nextx][nexty]=='#'||jud[nextx][nexty]==1)
				    continue;
				writ(nextx,nexty,tim);
				q.push(a);
				jud[nextx][nexty]=1;
				road[nextx][nexty][0]=temp.x;
				road[nextx][nexty][1]=temp.y;
			}
		}
		if(q.empty())
		    break;
	}
	if(ans==9999999)
	    cout<<"Peaceful world"<<endl;
	else
	{
		cout<<ans<<endl;
		cout<<ta<<" "<<tb<<endl;
		int aa,bb;
		for(i=ans;i>0;i--)
		{
			cout<<road[ta][tb][0]<<" "<<road[ta][tb][1]<<endl;
			aa=road[ta][tb][0];                                  
			bb=road[ta][tb][1];
			ta=aa;
			tb=bb;
		}
	}
}
