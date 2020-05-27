#include"stdio.h"
int main()
{
	int n,p,i,j;
	while(scanf("%d%d",&n,&p)!=EOF)
	{
		for(i=0;(n%2==0?i<=(n-2)/2:i<=(n-1)/2);i++)
		{
			for(j=1;j<=i;j++)
			    printf(".");
			if(2*i+2*p>=n+p-1) {
			    for(j=1;j<=n+p-1-2*i;j++)
			        printf("*");
	            goto k;
			}
			for(j=1;j<=p;j++)
			    printf("*");
			for(j=1;j<=n-p-2*i-1;j++)
			    printf(".");
			for(j=1;j<=p;j++)
			    printf("*");
			k:for(j=1;j<=i;j++)
			    printf(".");
			printf("\n");
		}                                              //ÉÏ°ë²¿·Ö
		for((n%2==0?i=(n-2)/2:i=(n-3)/2);i>=0;i--)
		{
			for(j=1;j<=i;j++)
			    printf(".");
		   	if(2*i+2*p>=n+p-1) {
			    for(j=1;j<=n+p-1-2*i;j++)
			        printf("*");
	            goto kk;
			}
			for(j=1;j<=p;j++)
			    printf("*");
			for(j=1;j<=n-p-2*i-1;j++)
			    printf(".");
			for(j=1;j<=p;j++)
			    printf("*");
			kk:for(j=1;j<=i;j++)
			    printf(".");
			printf("\n");
		} 
		
	}
}
