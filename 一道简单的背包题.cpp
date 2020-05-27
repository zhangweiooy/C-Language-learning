#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,v,dp[5000],a[2002];
int main()
{
	cin>>n>>v;
	int i,j,temp;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		if(temp%v==0)
		    temp=v;
		else
		    temp=temp%v;
		a[i]=temp;
	}
	for(i=0;i<n;i++)
	{
		for(j=2*v;j>=a[i];j--)
	    {
		    dp[j]+=dp[j-a[i]];
		    dp[j]%=10000000;
	    }
	    for(j=v+1;j<=2*v;j++) 
	    {
	    	dp[j-v]+=dp[j];
	    	dp[j]=0;
	    	dp[j-v]%=10000000;
		}
	}
	cout<<dp[v]%10000000<<endl;
}
