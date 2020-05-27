#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
	int time;
	int p;
}a[200];
int main()
{
	int n,i,j,temp;
	cin>>n;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		cin>>a[i].p;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		    a[j].time=0;
		temp=i;
		a[temp].time++; 
		while(1)
		{
			a[a[temp].p].time++;
			temp=a[temp].p;
			
				if(a[temp].time==2)
				{
					if(i==1)
					    if(i==n)
					        cout<<temp<<endl;
					    else
					        cout<<temp;
					else if(i==n)
					         cout<<" "<<temp<<endl;
					     else 
					         cout<<" "<<temp;
					break;
				}
			
		}
	}
 } 
