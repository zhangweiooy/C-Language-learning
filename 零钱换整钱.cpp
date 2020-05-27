#include"stdio.h"
int main()
{
	
	long int n,judge=0,ha,hb,hc,ia=0,ib=0,ic=0;
	scanf("%ld",&n);
    for(ic=0;ic<=n*10;ic++)
    {
    	hc=ic*20;
		for(ib=0;ib<n*20;ib++)
    	{
    		hb=ib*15;
			ia=n*100-ic*10-ib*5;
			ha=ia*18;
    		if(ha==hb&&hb==hc)
    		{
			    judge=1;
			    goto k;
			}
		}
	}
	k:
		if(judge==0)
		    printf("No change.\n");
		else
		    printf("%ld,%ld,%ld\n",ia,ib,ic);
	return 0;
}
