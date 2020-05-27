#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,j,Case=0,max=-111111,n,a[100002];
	cin>>t;
	while(t--)
	{
		cin>>n;
		Case++;
		int s=0,temp=0,begin=1,tmp=1,end=1;
		for(i=1;i<=n;i++)    
		{
			cin>>a[i];
			if(a[i]>max)
			{
				max=a[i];
				begin=i;
			}
		}
		if(max<0)
		{
			printf("Case %d:\n",Case);
		    cout<<max<<' '<<begin<<' '<<begin<<endl<<endl;
		    continue ;
		}
		s=temp=a[1];
		for(i=2;i<=n;i++)
		{
			if(temp>=0)
			    temp+=a[i];
			else
			{
				temp=a[i];
				tmp=i;
			}
			if(temp>s)
			{
				s=temp;
				end=i;
				begin=tmp;
			}
		}
		printf("Case %d:\n",Case);
		cout<<s<<' '<<begin<<' '<<end<<endl;
		if(t)
		    cout<<endl;
	}
	return 0;
}
