#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	long long n,s[2020],dp[2020];
	int i,j,left,right,flag1=0,flag2=0;
	scanf("%d",&n);
	dp[0]=1;
	dp[1]=1;
	for(i=0;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(i=1;i<=n;i++)
	{
		flag1=0;
		flag2=0; 
		for(j=i;j>=0;j--)
		{
			if(s[j]<s[i]&&flag1==0)
			{
				left=j;
				flag1=1;
			}
			if(s[j]>s[i]&&flag2==0)
			{
				right=j;
				flag2=1;
			}
		}
		if(flag1==1&&flag2==1)
		    dp[i]=dp[left]+dp[right];
		else
		    dp[i]=dp[i-1];
		dp[i]%=2147483647;
	}
	printf("%lld\n",dp[n]%2147483647);
}
