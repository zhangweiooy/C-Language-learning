#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int t,N,V,i,j,dp[1005],v[1005],w[1005];
int main()
{
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>N>>V;
		for(i=1;i<=N;i++)
		    cin>>w[i];
		for(i=1;i<=N;i++)
		    cin>>v[i];
		for(i=1;i<=N;i++)
		    for(j=V;j>=v[i];j--)
		        dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		int maxvalue=-1000;
		for(j=0;j<=V;j++)
		    maxvalue=max(maxvalue,dp[j]);
		cout<<maxvalue<<endl;
		memset(v,0,sizeof(v));
	} 
}
