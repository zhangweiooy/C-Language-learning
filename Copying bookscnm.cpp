#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long book[502],m,k;
bool flag[502];
long long bsearch(long long a)
{
	long long count=1,temp=0;
	memset(flag,false,sizeof(flag));
	for(long long i=m-1;i>=0;i--)
	{
		temp+=book[i];
		if(temp>a)
		{
		    count++;
		    temp=book[i];
		    flag[i]=true;
		}
	}
	return count;
}
int main()
{
	long long i,n,mmp;
	cin>>n;
	while(n--)
	{
		cin>>m>>k;
	
		long long left=0,mid,right=0;
		for(i=0;i<m;i++)
		{
			cin>>book[i];
			if(book[i]>left)    
			    left=book[i];
			right+=book[i];
	    }
		while(left<right)
		{
			mid=(left+right)/2;
			if(bsearch(mid)<=k)
			    right=mid;
			else
			    left=mid+1;
		}	
		mmp=bsearch(right);
		while(mmp<k)
		    for(i=0;i<m;i++)
			    if(!flag[i])
			    {
			    	flag[i]=true;
			        mmp++;
			        break;
				}
		cout<<book[0];
		for(i=1;i<m;i++)
		{
			if(flag[i-1])
			    cout<<" /";
			printf(" %lld",book[i]);
			
		}
		cout<<endl;
	}
	return 0;
 } 
