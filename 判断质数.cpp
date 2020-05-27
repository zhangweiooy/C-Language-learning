#include"stdio.h"
#include"math.h"
main()
{
	int n,a;
	k:while(scanf("%d",&n)!=EOF)
	{
		for(a=2;a<=sqrt(n);a++)
	    {
	    	if(n%a==0)
	    	    {
				printf("NO\n");
				goto k;
			    }
			    
		}
		printf("YES\n");
	}
}
