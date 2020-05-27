#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,i,q;
	cin>>n;
	int x[n];
	for(i=0;i<n;i++)    cin>>x[i];
	cin>>q;
	int m[q];
	for(i=0;i<q;i++)    cin>>m[i];
	stable_sort(x,x+n);
	for(i=0;i<q;i++)
	{
		int *temp=upper_bound(x,x+n,m[i]);
		cout<<temp-x<<endl;
	}
	return  0;
 } 
