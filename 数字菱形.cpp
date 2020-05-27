#include"stdio.h"
int main()
{
	int n,i,k,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=2*n-2*i;j++)
		    printf(" "); 
		for(k=1;k<=2*i-1;k++) 
		{ 
		    if(k<i)
			    printf("%-2d",n+1-k); 
			if(k>=i)      
		        printf("%-2d",n+1-2*i+k);
		} 
		printf("\n");                   //ÉÏ°ë²¿·Ö 
	} 
	for(i=n-1;i>0;i--)
	{
		for(j=1;j<=2*n-2*i;j++)
		    printf(" "); 
		for(k=1;k<=2*i-1;k++) 
		{ 
		    if(k<i)
			    printf("%-2d",n+1-k); 
			if(k>=i)      
		        printf("%-2d",n+1-2*i+k);
		} 
		printf("\n"); 
	} 
} 
