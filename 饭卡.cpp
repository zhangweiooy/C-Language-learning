#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring> 
using namespace std;
int i,j,n,m,a[1005],dp[1002];
int main()
{
	while(1)
	{
		cin>>n;
		if(n==0)
		    break;
		for(i=1;i<=n;i++)
			cin>>a[i];
		cin>>m;
		if(m<5){
			cout<<m<<endl;
			continue;
		}
		m-=5;            //��ʾ��jԪǮ����ǰi�����е�ĳЩ��
		sort(a+1,a+1+n);//�ܹ��򵽵Ĳ�Ʒ�ļ۸�֮�͵����ֵ��
	    memset(dp,0,sizeof(dp));
        for(i=1;i<=n-1;i++)
            for(j=m;j>=a[i];j--)
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		int maxcost=-10000;
		for(j=0;j<=m;j++)
		    if(dp[j]>maxcost)
		        maxcost=dp[j];
		cout<<m+5-maxcost-a[n]<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}
