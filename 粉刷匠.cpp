#include<stdio.h>
#define mod 998244353
long long dp[2005],dpw[2005];
long long calculate1(long long l,long long r,long long t)
{
	long long sum1=0,sum2=0,j;
	for(j=l;j<=r;j++)
	{
		sum1+=dp[j];
		sum1%=mod;
		sum2+=dpw[j];
		sum2%=mod; 
	}
	
	return sum1*t+sum2;
}
long long calculate2(long long l,long long r)
{
	long long sum=0,j;
	for(j=1;j<=r;j++)
	{
		sum+=dpw[j];
		sum%=mod;
	}
	return sum;
}
long long calculate3(long long l,long long r)
{
	long long sum=0,j;
	for(j=1;j<=r;j++)
	{
		sum+=dp[j];
		sum%=mod;
	}
	return sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	int n,m,k,i;
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<k;i++)
		{
			dp[i]=0;
			dpw[i]=1;
		}
		for(i=k;i<=n;i++)
		{
			dp[i] = calculate1(1,i-k,m-1)+ 1;
			dpw[i] = (calculate3(1,i-1)) * m + 1;
			dp[i]%=mod;
			dpw[i]%=mod;
		}
		long long ans=dp[n]*m+dpw[n];
		ans%=mod;
		printf("%d\n",ans);
	}
 } 
