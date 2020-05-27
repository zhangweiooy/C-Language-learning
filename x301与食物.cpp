#include"stdio.h"
int main()
{
	int i,j;
	long n; 
	while(scanf("%ld",&n)!=EOF)
	{
	
	long a[20000],b[2][20000];
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
    	b[0][i]=0;b[1][i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		    if(b[0][j]==a[i])
		    {   b[0][j]=0;
		        b[1][j]=0;
		    }

			b[0][i]=a[i];
			b[1][i]=n-i;
	
	}
	int max=0;
	for(i=0;i<n;i++)
	{
		if(b[1][i]>b[1][max]&&b[1][i]!=0)
		    max=i;
	}
	printf("%ld\n",b[0][max]);
    }
    return 0;
}
