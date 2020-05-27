#include"stdio.h"
void sort(long d[],int n)
{
	int i,min,j;
	long assist;
	for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			    if(d[min]>d[j])
			        min=j;
			if(min!=i)
			{
			    assist=d[min];
			    d[min]=d[i];
			    d[i]=assist;
			}	
		}
	return ;
}
int main()
{
	int m,n,count=0,i,j;
	long r[1000],a[1000];
	scanf("%d",&m);
	for(i=0;i<m;i++)
	    scanf("%ld",&r[i]);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%ld",&a[i]);
	sort(r,m);
	sort(a,n);
	for( i=j=0 ; i<m && j<n ; )
	{
		if(a[j]<r[i])
		{
			j++;
			continue ;
		}
		if(a[j]>=r[i])
		{
			count++;
			j++;
			i++;
		}
	}
	printf("%d\n",count);
	return 0;
}
