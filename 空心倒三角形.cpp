#include"stdio.h"
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=2*n-1;i++)
	    printf("*");
	printf("\n");               //µÚÒ»ÐÐ 
	if(n==0||n==1)
	    return 0; 
	for(i=2;i<=n;i++)
	{
	    for(j=1;j<=2*n-1;j++)
		{
		    if(j-i==0)
			{    printf("*");
			    continue;
			} 
			if(j+i<2*n)
			    printf(" ");
			if(j+i==2*n)
			{
			    printf("*");
				printf("\n");
				break; 
			} 
			
		} 
		
	} 
	printf("\n"); 
} 
