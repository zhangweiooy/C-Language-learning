#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll cheak(ll x)
{
	ll i,j=1,k=0;
	for(i=2;i*i*i<=x;i++)
	    k+=x/(i*i*i);
	return k;
}
int main()
{
	ll m;
	cin>>m;
	ll left=0,right=1e16;
	while(left<right)
	{
		ll mid=(left+right)>>1;
		if(cheak(mid)>=m)  //最小值，应尽量小 
		    right=mid;
		else
		    left=mid+1;
	}
	if(cheak(left)==m)
	    cout<<left;
	else
	    cout<<-1;
	return 0;
}
