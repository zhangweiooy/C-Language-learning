#include"stdio.h"
int main()
{
    int n,i=0,j=0;
	scanf("%d",&n);
	int a[n][n];
    a[0][0]=1;
    for(j=1;j<n;j++)
	{
	    if(j%2==0)
	        a[0][j]=2*j+a[0][j-1];
	    else  a[0][j]=1+a[0][j-1];
    }
    if(n%2!=0)
	{
	    for(i=1;i<n;i++)
        {
        	if(i%2==0)
    	        a[i][n-1]=(n-i)*2+a[i-1][n-1];
    	    else  a[i][n-1]=1+a[i-1][n-1];
	    }
    }
    else 
	{
	    for(i=1;i<n;i++)
            {
        	    if(i%2!=0)
    	            a[i][n-1]=(n-i)*2+a[i-1][n-1];
    	        else  a[i][n-1]=1+a[i-1][n-1];
	        }
    }
    for(i=1;i<n;i++)
    {
    	for(j=0;j<n-1;j++)
    	{
    		if((j+i)%2==0)
    		    a[i][j]=a[i-1][j+1]-1;
    		else  a[i][j]=a[i-1][j+1]+1;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==0)
			    printf("%2d",a[i][j]);
			else  printf("%3d",a[i][j]);
		}
		printf("\n");
	}
} 
