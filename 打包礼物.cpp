#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int id;
	int v;
}gift[100000];
bool cmp(node x,node y)
{
	return x.v>y.v;
}
int p[100000][3];
void sub(int j)
{
	if(p[j][1]!=0)
	    sub(p[j][0]);
	printf(" %d",gift[j].id);
	return;
}
int main()
{
	int k,m,j,i,count=0;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
	    p[i][0]=-1;
	    p[i][1]=0;
	    p[i][2]=-1;
	}
	
	for(i=0;i<k;i++)
	{
		scanf("%d",&gift[i].v);
		gift[i].id=i+1;
	}
	sort(gift,gift+k,cmp);
	for(i=k-1,m=k-1;m>=0;m--)
	{
		if(gift[m].v>=gift[i].v*2)
		{
			p[m][0]=i;//装着哪个礼物 
			p[m][1]=p[i][1]+1;//里面装几个礼物 
			p[i][2]=0;//是否被装 
			i--;
			count++;
		}
		
	}
	printf("%d\n",k-count);
	for(i=0;i<k;i++)
	{
		if(p[i][1]==0&&p[i][2]==-1)
		{
			printf("1 %d\n",gift[i].id);
		}
		if(p[i][1]!=0&&p[i][2]==-1)
		{
			printf("%d",p[i][1]+1);
			sub(i);
			printf("\n");
		}
	 } 
}
