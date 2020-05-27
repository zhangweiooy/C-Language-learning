#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int t;
	int d;
}a[6600];
struct node2
{
	int t;
	int d;
}b[5500];
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main()
{
	int n,q,k,i,ii,j,jj,ans,max,total=0;
	cin>>n>>q;
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		cin>>a[i].t>>a[i].d;
		total+=a[i].d;
	}
	sort(a,a+n,cmp);
	for(i=0,j=-1;i<n;i++)
	{
		if(b[j].t==a[i].t)
		{
			b[j].d+=a[i].d;
		}
		else
		{
			j++;
			b[j].t=a[i].t;
			b[j].d=a[i].d;
		}
	}
	for(i=0;i<q;i++)
	{
		cin>>k;
		ans=0;
		max=0;
		if(k>=b[j].t)
		    cout<<"0"<<endl;
		else
		{
			for(ii=0,jj=0;ii<=j;ii++)
			{
				if(ii!=0)
				    ans-=b[ii-1].d;
				for(;jj<=j;jj++)
				{
					if(b[jj].t>b[ii].t+k-1)
					    break;
					else
					    ans+=b[jj].d;
				}
				if(ans>max)
				    max=ans;
			}
			cout<<total-max<<endl;
		}
	}
}
