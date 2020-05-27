#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14159265
long long r[10005];
long long s[10005];
long long ans=0;
int m,n;
int judge(long long k)
{
	int count=0;
	for (int i=0;i<n;i++) 
	    count+=s[i]/k;
	if (count>=m) return 1; 
	return 0;
}
void binsearch(long long left,long long right)
{
	long long mid=(left+right)/2;
	if (left>right) 
	    return;
	if (judge(mid))
	{
		ans=mid;
		binsearch(mid+1,right);
	}
	else binsearch(left,mid-1);
}
int main()
{
	int i,j,flag=0;
	long long max;
	scanf("%d%d",&n,&m);
	m+=1;
	for (i=0;i<n;i++)
	{
		scanf("%ld",&r[i]);
		s[i]=PI*r[i]*r[i]*1000000;
		if(s[i]>0)
		    flag=1;
	}
	if (flag=0)
	{
		printf("0.0000\n");
		return 0;
	}
	for(max=s[0],i=1;i<n;i++)
	{
		if(s[i]>max)
		    max=s[i];
	}
	binsearch(0,max+1);
	printf("%.4f\n",ans/1000000.0);
	return 0;
}
