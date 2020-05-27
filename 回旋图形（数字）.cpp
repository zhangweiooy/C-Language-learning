#include"stdio.h"
int main()
{
	int n,i,circle,j=1;
	scanf("%d",&n);
	int a[n][n];
	for(circle=1;circle<=(n%2==0?n/2:(n-1)/2);circle++)
	{
		for(i=circle-1;i<=n-1-circle;i++,j++)
	    	a[circle-1][i]=j;
		for(i=circle-1;i<=n-circle-1;i++,j++)
			a[i][n-circle]=j;
		for(i=n-circle;i>=circle;i--,j++)
			a[n-circle][i]=j;
		for(i=n-circle;i>=circle;i--,j++)
			a[i][circle-1]=j;
	}
	if(n%2==1)
		a[(n-1)/2][(n-1)/2]=j;
	for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	    printf("%3d",a[i][j]);
    	printf("\n");
	}
}
