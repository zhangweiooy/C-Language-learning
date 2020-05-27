#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int f[102][102];
	for(i=0;i<n;i++)
	    for(j=0;j<=i;j++)
	        cin>>f[i][j];
	for(i=n-2;i>=0;i--)
	    for(j=0;j<=i;j++)
	        f[i][j]+=max(f[i+1][j],f[i+1][j+1]);
	cout<<f[0][0]<<endl;
	return 0;
}
