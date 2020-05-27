#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct point
{
	int x,y;
	int steps;   //步数 
};
point start,a[30];
int map[5][5];
int dir[4][2]={0,1,0,-1,1,0,-1,0}; //方向向量下,上,右,左
int fang[5][5];//记录上一步的方向向量
bool vst[5][5];
bool check(point s)
{
	if(!vst[s.x][s.y]&&s.x>=0&&s.y>=0&&s.y<5&&s.x<5)
	    return 1;
	else
	    return 0;
 } 
void bfs(point st)
{
	queue<point> q;
	point now,next;
	st.steps=0;
	q.push(st);
	vst[st.x][st.y]=1;
	int k=0,i,j;
	while(!q.empty())
	{
		now=q.front();
		if(now.x==4&&now.y==4)
		{
			a[k++]=now;
			next=now;
			while(1)
			{
				switch(fang[now.x][now.y])
				{
					case 0:
					    next.y=now.y-1;break;
					case 1:
						next.y=now.y+1;break;
					case 2:
						next.x=now.x-1;break;
					case 3:
						next.x=now.x+1;break;
				}
				a[k++]=next;
				now=next;
				if(next.x==0&&next.y==0)
				    break;
			}
			k--;
			while(k>=0)
			{
				printf("(%d, %d)\n",a[k].x,a[k].y);
				k--;
			}
			return ;
		}
		for(i=0;i<4;i++)     //搜索周边四个方向 
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			next.steps=now.steps+1;
			if(check(next))
			{
				fang[next.x][next.y]=i;
				q.push(next);
				vst[next.x][next.y]=1;
			}
		}
		q.pop();
	}
	return;
}
int main()
{
	int i,j;
	for(i=0;i<5;i++)
	    for(j=0;j<5;j++)
	    {
	    	cin>>map[i][j];
	    	if(map[i][j]==1)    vst[i][j]=true;
		}
	start.x=0,start.y=0;
	bfs(start);
	return 0;
}
