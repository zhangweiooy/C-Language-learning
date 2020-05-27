#include<cstdio>
#include<iostream>
using namespace std;
long long qpow(long long a,long long b)
{
	long long r=1;
	while(b)
	{
		if(b&1)
		    r*=a;
		a*=a;
		b>>=1;
	}
	return r;
}
int main()
{
	long long t,i,n,temp,sum1,sum2;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum1=n*(n+1)/2;
		sum2=temp=0;
		for(i=0;temp<=n/2;i++)
		{
			temp=qpow(2,i);
			sum2+=temp;
		}
		printf("%lld\n",sum1-sum2-sum2);
	}
	return 0;
}
