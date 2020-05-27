#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm> 
using namespace std;
double c,t,x[100000];
long long d[100000],v[100000];
int main()
{
	int T,n,q,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lf",&n,&c);
		int i=0,tt;
		tt=n;
		while(tt--)
		{
			scanf("%ld%lf%d",&v[i],&x[i],&d[i]);
			i++;
		}
		scanf("%d",&q);
		sort(v,v+n);
		while(q--)
		{
			scanf("%lf%d",&t,&k);
			printf("%.3lf\n",sqrt(2*c*t+v[k-1]*v[k-1]));
		}
	}
}
