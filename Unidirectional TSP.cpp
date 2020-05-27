#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int p[105];
int n,m,i,j;
int a[105][105],aa[105][105];
int find(int a,int b,int c)
{
	if(a<b){
		if(a<c)
			return a;
		else
			return c;
	}
	else{
		if(b>c)
			return c;
		else
			return b;
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		
		memset(p,0,sizeof(p));
		for(i=0;i<n;i++)
		    for(j=0;j<m;j++)
		    {
		    	cin>>a[i][j];
		    	aa[i][j]=a[i][j];
			}
		for(j=m-2;j>=0;j--)
		{
			for(i=0;i<n;i++)
			{
				if(i==0)
				    a[i][j]+=find(a[n-1][j+1],a[i][j+1],a[i+1][j+1]);
				else if(i==n-1)
				         a[i][j]+=find(a[i-1][j+1],a[i][j+1],a[0][j+1]);
				     else
					     a[i][j]+=find(a[i-1][j+1],a[i][j+1],a[i+1][j+1]);
			}
		}
		int s=a[0][0];
		p[0]=1;
		for(i=1;i<n;i++)
		    if(a[i][0]<s)
		    {
		    	s=a[i][0];
		    	p[0]=i+1;
			}   
		int temp=0,ans=s,k,pk[3];
		ans-=aa[p[0]-1][0];
		for(j=1;j<m;j++)
        {
        	pk[0]=(p[temp]-2==-1?n-1:p[temp]-2);
        	pk[1]=p[temp]-1;
        	pk[2]=(p[temp]==n?0:p[temp]);
        	sort(pk,pk+3);
        	for(k=0;k<3;k++)
        	    if(ans==a[pk[k]][j])
        	        break;
        	p[j]=pk[k]+1;
            ans=ans-aa[pk[k]][j];
            temp++;
        }
		for(j=0;j<m;j++)
		    if(j==0)
		        cout<<p[j];
		    else
		        cout<<' '<<p[j];
		cout<<endl;
		cout<<s<<endl;
	}
	return 0;
}
