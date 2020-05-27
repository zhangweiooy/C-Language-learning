#include"stdio.h"
int main()
{
	long m,n,i,a,b;
	while( scanf("%ld %ld",&m,&n)!=EOF)
	{
	  a=b=0;
	  if(m > n) 
	  {   
            i = m;  
            m = n;  
            n = i;  
      }  
	 

		while(m<=n)
		{
		    m%2==0?a=a+m*m:b=b+m*m*m;
		    ++m; 
		}
	  printf("%ld %ld\n",a,b);	
	
	} 
}
