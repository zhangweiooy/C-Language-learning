#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[500003];
int ans;
int l,n,m;
int cmp(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int judge(int k)
{
	int all=0,last=0; 
	if (a[1]>k) return 0;
	for (int i=2;i<=n;i++)
	{
		if (a[i]-last>k)
		{
			all++; last=a[i-1];
		}
	}
	all++;
	if (all>m) return 0;
	return 1;
}
void findans(int left,int right)
{
	if (left>right) 
	{
		return;
	}
	int mid=(left+right)/2;
	if (judge(mid)) 
	{
		ans=mid;
		findans(left,mid-1);
	}
	else findans(mid+1,right);
} 
int main()
{
	scanf("%d%d%d",&l,&n,&m);
	for (int i=1;i<=n;i++) 
	scanf("%d",&a[i]);
	a[n+1]=l;
	n++;
	qsort(a+1,n,sizeof(int),cmp);
	int max=a[1];
	for (int i=2;i<=n;i++)
		if (a[i]-a[i-1]>max) max=a[i]-a[i-1];
	findans(max,l);
	printf("%d\n",ans);
	return 0;
}
