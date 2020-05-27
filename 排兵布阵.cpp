#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,i,j;
long long ans=0,ax[100000],ay[100000];
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	    cin>>ax[i]>>ay[i];
	sort(ax,ax+n);
	sort(ay,ay+n);
	for(i=0;i<n;i++)
	    ax[i]=ax[i]-i;
	sort(ax,ax+n);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		ans+=ax[j]-ax[i];
		ans+=ay[j]-ay[i];
	}
	cout<<ans<<endl;
	return 0;
}
