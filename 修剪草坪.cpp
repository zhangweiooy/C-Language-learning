#include<cstdio>
#include<cstring>
#include<cstdlib> 
#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,flag=1,hr[110]={0},hc[110]={0},a[110][110];
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>hr[i])
			    hr[i]=a[i][j];
		}
	}
	for(j=0;j<m;j++)
	    for(i=0;i<n;i++)
	        if(a[i][j]>hc[j])
	            hc[j]=a[i][j];
	for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
	        if(a[i][j]!=hr[i]&&a[i][j]!=hc[j])
	            flag=0;
	if(flag==0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	cout<<"YES"<<endl;
	cout<<m+n<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" "<<hr[i]<<" "<<"R"<<endl;
	}
	for(j=0;j<m;j++)
	{
		cout<<j+1<<" "<<hc[j]<<" "<<"C"<<endl;
	}
}
