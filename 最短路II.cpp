#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
int e[100][100],dis[100],book[100];//e用来记录数组，dis用来记录初始点到各个点的位置，book用来标记，被标记的表示已经连接成最短路
int main()
{
    int n,m,t1,t2,t3,k,min1;
    while(1)
    {
    scanf("%d%d",&n,&m);
    if(n==0&&m==0)
        break;
    memset(e,inf,sizeof(e));
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=e[t2][t1]=t3;
    }
    for(int i=1; i<=n; i++)
        dis[i]=e[1][i];
    memset(book,0,sizeof(book));
    dis[1]=0;
    for(int i=1; i<=n; i++) //更新dis数组
    {
        min1=inf;
        for(int j=1; j<=n; j++)
        {
            if(book[j]==0&&dis[j]<min1)//每次找最短的边
            {
                min1=dis[j];
                k=j;
            }
        } 
        book[k]=1;
        for(int j=1; j<=n; j++)
        {
            if(e[k][j]<inf)
                if(dis[j]>dis[k]+e[k][j])//如果从起始点到j的距离大于起始点到k的距离加上k到j的距离就更新，专业术语松弛操作
                    dis[j]=dis[k]+e[k][j];
        }
    }
    printf("%d\n",dis[n]);
    }
    return 0;
}
