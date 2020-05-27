#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[502],b[502],c[502],x,s[502*502],k,flag;
void fun(int num)
{
	int left=0,right=k-1,mid;
	
	while(left<=right)
	{
		mid=(left+right)/2;
		if(s[mid]+num<x)
		    left=mid+1;
		else if(s[mid]+num>x)
		         right=mid-1;
		     else
		         {
		         	flag=1;
		         	return ;
				 }
	}
	return ;
}
int main()
{
	int l,n,i,m,t,j,cas=0;
	while(scanf("%d%d%d",&l,&n,&m)!=EOF){
		cas++;
		for(i=0;i<l;i++)
	        cin>>a[i];
	    for(i=0;i<n;i++)   cin>>b[i];
	    for(i=0;i<m;i++)   cin>>c[i];
	    cin>>t;
	    k=0;
	    for(i=0;i<l;i++)
	        for(j=0;j<n;j++)
	            s[k++]=a[i]+b[j];
	    sort(s,s+k);             //对数据较多的进行二分
		printf("Case %d:\n",cas); 
	    while(t--)
	    {
	    	cin>>x;
	    	flag=0;
	    	for(i=0;i<m;i++)
	    	    fun(c[i]);
	    	if(flag==1)
	    	    cout<<"YES"<<endl;
	    	else
	    	    cout<<"NO"<<endl;
		}
	}     
}
