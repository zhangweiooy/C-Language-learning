#include"stdio.h"
int main()
{
	int n,q;
	int a[100000],i,k[100000],he[100000],judge=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
		    scanf("%d",&a[i]);
	        if(i==0)
			    he[i]=a[i];
			else	he[i]=he[i-1]+a[i];
		}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		    scanf("%d",&k[i]);
		for(i=0;i<q;i++)
		{  
		    if(judge==1) printf(" ");
			printf("%d",he[k[i]-1]);
			judge=1;
		}
		printf("\n");
		judge=0; 
	}
}
