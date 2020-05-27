#include"stdio.h"
#include"math.h"
int main()
{
	long long n,p,s;
	k:while(scanf("%lld",&n)!=EOF)
	 {
	    for(p=1;p<=30;p++)
	    {
		s=pow(2,p);
		if(n==(s-1))
	        {
			printf("YES\n");
	        goto k;
			} 
		}
		printf("NO\n");
     }
}
