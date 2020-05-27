#include<cstdio>
using namespace std;
long long qpow(long long a,long long b)
{
	long long r=1;
	a=a%1000;
	while(b)
	{
		if(b&1)
		    r=r*a%1000;
		a=a*a%1000;
		b>>=1;
	}
	return r;
}
int main()
{
	long long ans,a,b;
	while(scanf("%lld %lld",&a,&b))
	{
		if(a==0&&b==0)
		    break;
		printf("%d\n",qpow(a,b)%1000);
	}
	return 0;
}
