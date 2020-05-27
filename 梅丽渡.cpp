#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;  
typedef long long ll;
int INF=0x3f3f3f3f;
int n,i,k;
ll a[500010],dp[2][500010];  
ll max(ll x,ll y)
{
	if(x>y)
	    return x;
	else
	    return y;
}
int main()  
{
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
		scanf("%lld",a+i);  
	for(i=0;i<=n;i++)
		dp[0][i]=0,dp[1][i]=0;    
    for(i=1,k=1;i<=3;i++,k^=1)   
    {
       	dp[k][i-1]=-INF;  
        ll maxpre=-INF;   
        for(int j=i;j<=n-3+i;j++)
        {
            maxpre=max(maxpre,dp[k^1][j-1]);    
            dp[k][j]=max(dp[k][j-1],maxpre)+a[j]; 
        }
    }
    ll ans=-INF;
    for(i=3;i<=n;i++)   
        ans=max(ans,dp[1][i]);
    printf("%lld\n",ans);
}
