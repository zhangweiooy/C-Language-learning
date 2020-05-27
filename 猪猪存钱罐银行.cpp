#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long T,E,F,V,N,p[10005],w[10005],dp[10005],i,j;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>E>>F;
		cin>>N;
		for(i=1;i<=N;i++)
			cin>>p[i]>>w[i];
		V=F-E;
		memset(dp,0x3f3f3f3f,sizeof(dp));      //其实dp的元素并非999999 
		dp[0]=0;                           //，故后面比较时不可用数 
		for(i=1;i<=N;i++)
		    for(j=w[i];j<=V;j++)
		        dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
		if(dp[V]==dp[10004])
		    cout<<"This is impossible."<<endl;
		else
		    cout<<"The minimum amount of money in the piggy-bank is "<<dp[F-E]<<"."<<endl;   
	}
	return 0;
}
