#include"stdio.h"
int main()
{
	int n,i,judge=0,j,assist,min,a[10000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		    scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			    if(a[min]>a[j])
			        min=j;
			if(min!=i)
			{
			    assist=a[min];
			    a[min]=a[i];
			    a[i]=assist;
			}	
		}
		for(i=0;i<n;i++)
		{
		    if(judge==1) 
			    printf(" ");
			printf("%d",a[i]);
		    judge=1;
	    }
	    printf("\n"); 
	    judge=0;
	}
}
