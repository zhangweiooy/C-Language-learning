#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
int e[100][100],dis[100],book[100];//e������¼���飬dis������¼��ʼ�㵽�������λ�ã�book������ǣ�����ǵı�ʾ�Ѿ����ӳ����·
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
    for(int i=1; i<=n; i++) //����dis����
    {
        min1=inf;
        for(int j=1; j<=n; j++)
        {
            if(book[j]==0&&dis[j]<min1)//ÿ������̵ı�
            {
                min1=dis[j];
                k=j;
            }
        } 
        book[k]=1;
        for(int j=1; j<=n; j++)
        {
            if(e[k][j]<inf)
                if(dis[j]>dis[k]+e[k][j])//�������ʼ�㵽j�ľ��������ʼ�㵽k�ľ������k��j�ľ���͸��£�רҵ�����ɳڲ���
                    dis[j]=dis[k]+e[k][j];
        }
    }
    printf("%d\n",dis[n]);
    }
    return 0;
}
