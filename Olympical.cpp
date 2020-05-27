#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int s[100005];
bool vis[10];
int judge(int x)
{
	memset(vis,false,sizeof(vis));
	while(x)
	{
		if(vis[x%10])
		    return 0;
		vis[x%10]=true;
		x/=10;
	}
	return 1;
}
int main()
{
	int t,a,b,i;     //先把表都打出来 
	s[0]=0;
	for(i=1;i<100005;i++)
	    s[i]=s[i-1]+judge(i);
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<s[b]-s[a-1]<<endl;
	}
	return 0;
}
