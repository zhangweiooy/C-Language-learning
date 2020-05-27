#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int a[200005],p[200005];
long long f[200005][2];//0Å¼1Ææ 
int n,i;
long long max(long long a,long long b)
{
    if(a>b)
	    return a;
	else
	    return b;	
} 
void dp()
{
	long long t0,t1;
    t0=max(f[p[i]][0]+f[i][0],f[p[i]][1]+f[i][1]);
    t1=max(f[p[i]][1]+f[i][0],f[p[i]][0]+f[i][1]);
    f[p[i]][0]=t0;
    f[p[i]][1]=t1;
    return ;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
        scanf("%d %d",&p[i],&a[i]);
        f[i][0]=0;
        f[i][1]=-INF;
    }
    for(i=n;i>0;i--)
	{
        f[i][1]=max(f[i][1],f[i][0]+a[i]);
        if(i==1)
		    break;
        dp();
    }
    printf("%lld\n",f[1][1]);
    return 0;
}
