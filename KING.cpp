#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
__int64 dp[22];

__int64 f(int b,int a) 
{
    int c=1,i; 
	for(i=1;i<=a;i++) 
	{
	    c*=(b-i+1);
	    c=c/i;
	}                             //排列组合C(b,a)，从多少数中选几个顺序排列 
	return(c);
} 
int main()
{
     memset(dp,0,sizeof(dp));
     dp[1]=1,dp[2]=2;
     int i,j;
     for(i=3;i<=20;i++)
     {
         dp[i]+=dp[i-1];  //最高的在两边*c(i,0)
         for(j=1;j<i-1;j++)  //前面有j个后面有i-1-j个
         {
             if(j==1||i-1-j==1)
               dp[i]+=(dp[j]*dp[i-1-j]>>1)*f(i-1,j);
             else
               dp[i]+=(dp[j]>>1)*(dp[i-1-j]>>1)*f(i-1,j);
         }
     }
     int tes,cas,x;
     scanf("%d",&tes);
     while(tes--)
     {
          scanf("%d%d",&cas,&x);
          printf("%d %I64d\n",cas,dp[x]);
     }
     return 0;
}
