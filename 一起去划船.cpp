#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100005];
int main()
{
	int t,i,j,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		sort(a,a+n+1);
		int ans=0,s=0,te,k,judge;
		for(i=1;i<=n;i++)
		{
			if(a[i]>=s)
			{
				ans++;
				s+=a[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
