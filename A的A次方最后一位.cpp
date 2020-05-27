#include<cstdio>
#include<iostream>
using namespace std;
long long qpow(long long a,long long b)
{
	long long r=1;
	a=a%10;
	while(b)
	{
		if(b&1)
		    r=r*a%10;
		a=a*a%10;
		b>>=1;
	}
	return r;
}
int main()
{
	long long ans,a,t;
	cin>>t;
	while(t--)
	{
		cin>>a;
		printf("%d\n",qpow(a,a)%10);
	}
	return 0;
}
