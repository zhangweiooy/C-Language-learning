#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll f(ll b,ll a) 
{
    ll c=1,i; 
	for(i=1;i<=a;i++) 
	{
	    c*=(b-i+1);
	    c=c/i;
	}                             //�������C(b,a)���Ӷ�������ѡ����˳������ 
	return(c);
} 
ll dp[22];
int main()
{
	memset(dp,0,sizeof(dp));
	dp[1]=1,dp[2]=2,dp[3]=4;
	int i,j;
	for(i=4;i<=20;i++)    //��� 
	{
		dp[i]+=dp[i-1];
		for(j=1;j<i-1;j++)    //��ǰ��n-1������ѡj�� 
		    if(j==1||i-1-j==1)//�͸ߵ͸ߵ͸��ظ������2 
		        dp[i]+=(dp[j]*dp[i-1-j]/2)*f(i-1,j);
		    else
		        dp[i]+=(dp[j]/2)*(dp[i-1-j]/2)*f(i-1,j);         
	}
	int t,d,n;
	cin>>t;
	while(t--)
	{
		cin>>d>>n;
		cout<<d<<" "<<dp[n]<<endl;
	}
	return 0;
}
