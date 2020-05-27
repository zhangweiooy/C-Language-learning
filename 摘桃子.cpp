#include<cstdio>
#include<iostream>
#include <algorithm>
using namespace std;
int a[50000]={0},n,v,ans=0;
int main()
{
	cin>>n>>v;
	int temp1,temp2,max=0;
	for(int i=1;i<=n;i++)
	{
		cin>>temp1>>temp2;
		if(temp1>max)
		    max=temp1;
		if(a[temp1]!=0)
		    a[temp1]+=temp2;
		else
		    a[temp1]=temp2;
	} 
	for(int i=1;i<=max+1;i++)
	{
		if(i>1)
		{
			  if(a[i-1]>0)
			  {
			  	if(a[i-1]>=v)
			  	{
			  		ans+=v;
			  		a[i-1]=0;
				  }
				else{
					ans+=a[i-1];
					if(a[i]>=(v-a[i-1]))
					{
						a[i]-=(v-a[i-1]);
						ans+=(v-a[i-1]);
					 } 
					else {
						ans+=a[i];
						a[i]=0;
					}
				}
			  }
			  else{
			  	if(a[i]>0)
			  	{
			  		if(a[i]>=v)
			  		{
			  			ans+=v;
			  			a[i]-=v;
					  }
					else{
						ans+=a[i];
						a[i]=0;
					}
				  }
			  }
		}
		else if(a[i]>=v)
		     {
		     	ans+=v;
				a[i]-=v; 
			 }
			 else {
			 	ans+=a[i];
			 	a[i]=0;
			 } 
	}
	cout<<ans<<endl;
}
