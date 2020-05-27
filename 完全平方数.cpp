#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int T;
	long long k,i,j,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&k);
		n=1; 
		i=0;
		for(j=1; ;)
		{
			
			if(j*j==(4*n+12))
			{
				i++;
			}
			if(i==k)
			    break;
			if(j*j>=(4*n+12))
			    n++;
			else
			    j++;
		}
		printf("%lld\n",n);
	}
	return 0;
 } 
