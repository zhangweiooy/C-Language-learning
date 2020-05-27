#include<cstdio>
#include<stack>
using namespace std;
typedef struct pos
{
	int x,y;
} pos;
int map[102][102];//地图 
int dir[4][2]={0,-1,-1,0,0,1,1,0};//方向数组 
stack<pos>rode; //路径栈 
int find_rode(int row,int col)//找路 
{
	pos first;
	first.x=row;
	first.y=col;
	rode.push(first);
	while(!rode.empty())
	{
		int flag=0;
		pos point;
		point=rode.top();
		for(int i=0;i<4;i++)
		{
			if(point.x+dir[i][0]>0&&point.x+dir[i][0]<=row&&point.y+dir[i][1]>0&&point.y+dir[i][1]<=col)
			    if(!map[point.x+dir[i][0]][point.y+dir[i][1]])
			    {
			    	point.x+=dir[i][0];
		    		point.y+=dir[i][1];
		    		rode.push(point);
		    		map[point.x][point.y]=1;
		    		flag=1;
		     		break;
		    	}
		}
		if(rode.top().x==1&&rode.top().y==1)
		    return 1;
		if(!flag)
		{
			map[point.x][point.y]=1;
			rode.pop();
		}
	}
	return 0;
}
int main()
{
	int col,row;
	scanf("%d%d",&col,&row);
	for(int i=1;i<=row;i++)
		for(int j=1;j<=col;j++)
		    scanf("%d",&map[i][j]);
	if(map[row][col]!=0)
	    printf("There is no solution!\n");
	else
	{
		if(find_rode(row,col))
		{
			while(!rode.empty())
			{
				printf("<%d,%d> ",rode.top().x,rode.top().y);
				rode.pop();
			}
			printf("\n");
		}
		else
		    printf("There is no solution!\n");
		 
	}
}
