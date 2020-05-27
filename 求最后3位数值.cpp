#include"stdio.h"
int main()
{
	long a,n,i,judge=0,s=1;
	scanf("%ld %ld",&a,&n);
	if(n==0)
	   s=1;
	for(i=1;i<=n;i++)
	{
	    s=s*a;
	    if(s>1000){
		    s=s%1000;
		    judge=1;
		}    
	}
	if(s<100&&judge==1)
	    printf("The last 3 numbers is %03ld.\n",s);
	else     
	    printf("The last 3 numbers is %ld.\n",s);
}
