#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[250002];
int main()
{
	int n,sum,i,j,temp,k,v[5005],m;
	while(1)
	{
		cin>>n;
		if(n<=0)
		    break;
		sum=0;
		k=1;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			cin>>temp>>m;
			while(m--)
			{
				v[k++]=temp;
				sum+=temp;
			}
		}
		for(i=1;i<=k-1;i++)
		    for(j=sum/2;j>=v[i];j--)
		        dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		cout<<sum-dp[sum/2]<<' '<<dp[sum/2]<<endl;
	}
	return 0;
}
