#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct node{
	int l;
	int r;
	int id;
}t[300000];
bool cmp(struct node a,struct node b)
{
	if(a.l==b.l)
	    return a.r>b.r;
	else
	    return a.l<b.l;
}
int main()
{
	int n,i,flag=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t[i].l>>t[i].r;
		t[i].id=i+1;
	}
	if(n==1)
	    cout<<"-1"<<endl;
	sort(t,t+n,cmp);
	for(i=1;i<n;i++)
	{
		if(t[i].r<=t[i-1].r)
		{
			flag=1;
			cout<<t[i].id<<endl;
			break;
		}
		if(i<n-1)
		    if(t[i-1].r+1>=t[i+1].l&&t[i+1].r>=t[i].r)
		    {
		    	flag=1;
		        cout<<t[i].id<<endl;
			    break;	
			}
	 } 
	if(flag==0)
	    cout<<"-1"<<endl;
}
