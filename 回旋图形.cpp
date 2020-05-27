#include"stdio.h"
int main()
{
	int n,i,circle,j=0;
	scanf("%d",&n);
	char c[26],a[n][n];
	c[0]='A';
	for(i=0;i<25;i++)
	    c[i+1]=c[i]+1;
	for(circle=1;circle<=(n%2==0?n/2:(n-1)/2);circle++)
	{
		for(i=circle-1;i<=n-1-circle;i++)
	    {
	    	if(j==26)    j=0;
	    	a[circle-1][i]=c[j];
	    	j++;
		}
		for(i=circle-1;i<=n-circle-1;i++)
		{
			if(j==26)    j=0;
			a[i][n-circle]=c[j];
			j++;
		}
		for(i=n-circle;i>=circle;i--)
		{
			if(j==26)    j=0;
			a[n-circle][i]=c[j];
			j++;
		}
		for(i=n-circle;i>=circle;i--)
		{
			if(j==26)    j=0;
			a[i][circle-1]=c[j];
			j++;
		}
	}
	if(n%2==1)
	{
		if(j==26)    j=0;
		a[(n-1)/2][(n-1)/2]=c[j];
	}
	for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	    printf("%c",a[i][j]);
    	printf("\n");
	}
}
