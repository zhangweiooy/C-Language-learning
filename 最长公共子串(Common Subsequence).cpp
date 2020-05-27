#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1005][1005]; 
int main()
{
	char a[100000],b[100000];
	int ans,i,j,lena,lenb;
	while(scanf("%s %s",a,b)!=EOF)
	{
		lena=strlen(a);
		lenb=strlen(b);
		i=j=ans=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=lena;i++)
		    for(j=1;j<=lenb;j++)
		    {
			    if(a[i-1]==b[j-1])
			        dp[i][j]=dp[i-1][j-1]+1;
			    else
			        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		    }
		cout<<dp[lena][lenb]<<endl;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
	}
	return 0;
}
