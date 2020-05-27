#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
struct m
{
	double left;
	double right;
}region[1005];
int cmp(m a,m b)
{
	return a.left<b.left;
}
int main()
{
	int n,d,i,cas=0,ans=0;
	while(scanf("%d %d",&n,&d))
	{
		ans=0;
		cas++;
		if(n==0&&d==0)
		    break;
		int judge=1,x[1005],y[1005];
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			if(y[i]>d)
			    judge=0;
		}
		if(judge==0)
		{
			printf("Case %d: -1\n",cas);
			continue;
		}
		for(i=0;i<n;i++)
		{
			double temp=sqrt(d*d*1.0-y[i]*y[i]*1.0);
			region[i].left=x[i]-temp;
			region[i].right=x[i]+temp;
		}
		sort(region,region+n,cmp);
		double now=-1000000.00000;//代表现在雷达的位置  （尽可能向右安） 
		for(i=0;i<n;i++)
		{
			if(region[i].left>now)
			{
				ans++;
				now=region[i].right;
			}
			else
			{
				if(region[i].right<now)
				    now=region[i].right;
			}
		}
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}
