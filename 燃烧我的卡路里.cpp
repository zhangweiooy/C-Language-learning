#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream> 
using namespace std;
int main()
{
	int t,ax,ay,bx,by,ans;
	cin>>t;
	while(t--)
	{
		cin>>ax>>ay;
		cin>>bx>>by;
		ans=(abs(ay-by)+abs(bx-ax)+2)*2;
		if(ax==bx||ay==by)
		{
			ans+=2;
		}
		cout<<ans<<endl;
	}
}
