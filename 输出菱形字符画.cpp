#include"stdio.h"
main()
{
	int a,b,c,n,i,j,m;
	k:while(scanf("%d",&n)!=EOF)
	{
		b=(n-1)/2;
		for(a=1;a<=b;a++)
		     printf(" ");
		printf("*\n");     
		for(c=2;c<(n+1)/2;c++)
		{
		    for(i=1;i<=(n+1)/2-c;i++)
		        printf(" ");
		    printf("*");
			for(j=1;j<=2*c-3;j++)
			    printf(" ");    
	        printf("*\n");	
		}
		if(c==(n+1)/2)
		{
			printf("*");
			m=1;
			while(m<=n-2)
			    {
				printf(" ");
			    m++;
				}
			printf("*\n");    
		}
		for(c=(n+3)/2;c<=n;c++)
		{
			for(i=1;i<=c-(n+1)/2;i++)
			     printf(" ");
			if(c==n)
			    {
			    printf("*\n");
				goto k;
				}
			printf("*");
			for(j=1;j<=2*n-2*c-1;j++)
			     printf(" ");
		    printf("*\n");		      
		}
		
	}
}
