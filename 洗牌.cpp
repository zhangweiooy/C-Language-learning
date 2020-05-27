#include"stdio.h"
#include"string.h" 
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	int a[2*n],b[2*n],c[2*n];
	for(i=0;i<2*n;i++)
	    a[i]=i+1;            //对每一张 牌标号
	for(i=0;i<n;i++)
	{
		b[2*i]=a[n+i];
		b[2*i+1]=a[i];
	}
	count++;
	if(! memcmp(b,a,2*n))
	{
		printf("%d\n",count);
		return 0;
	}
k:	for(i=0;i<n;i++)
	{
		c[2*i]=b[n+i];
		c[2*i+1]=b[i];
	}
	count++;
	if(! memcmp(c,a,2*n))
	{
		printf("%d\n",count);
		return 0;
	}
	for(i=0;i<n;i++)
	{
		b[2*i]=c[n+i];
		b[2*i+1]=c[i];
	}
	count++;
	if(! memcmp(b,a,2*n))
	{
		printf("%d\n",count);
		return 0;
	}
	goto k;
 } 
