#include"stdio.h"
#include"stdlib.h"
int cmp(const void *a,const void *b)
{
	return *(long long *)b - *(long long*)a;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		int flag=0;
		long long n,ans=0,s=0;
		scanf("%ld",&n);
		long long a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		for(i=0;i<n;i++)
		{
			if(a[i]>0)  flag=1;
			s+=a[i];
			if(s>ans)
			{
				ans=s;
			}
		}
		if(flag==0) ans=a[0];
		printf("%lld\n",ans);
	}
}
