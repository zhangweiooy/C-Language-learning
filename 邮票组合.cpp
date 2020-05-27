#include"stdio.h"
int main()
{
	int a,b,c,d,an,bn,cn,dn,i=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b)
	    a=b;
	if(a>c)
	    a=c;
	if(a>d)
	    a=d;
	if(b>c)
	    b=c;
	if(b>d)
	    b=d;
	if(c>d)
	    c=d;
	k:
	for(dn=0;dn<=5;dn++)
	{
		for(cn=0;cn<=5-dn;cn++)
		{
			for(bn=0;bn<=5-cn-dn;bn++)
			{
				for(an=0;an<=5-cn-bn-dn;an++)
				{
					
					if(i==(a*an+b*bn+c*cn+d*dn))
					    {
					    	i++;
					    	goto k;
						}
		            
				}
			  
			}
			
		}
		
	}
	
	printf("The max is %d.\n",i-1);     
}
