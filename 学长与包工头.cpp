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
	int n,i,j;
	long w[1000],ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%ld",&w[i]);
	sort(w,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		    ans+=w[j];
	}
	printf("%ld\n",ans);
	return 0;
}
