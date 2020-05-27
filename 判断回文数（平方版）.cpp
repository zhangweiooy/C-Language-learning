#include"stdio.h"
int main()
{
	int n,i=1,a,b=0;
	scanf("%d",&n);
	while(i<n)
	{
    	for(a=i*i;a>0;)
    	{
	    	b=b*10+a%10;
	    	a=a/10;
	    }
    	if(b==i*i)
	        printf("%d\n",i);
    	i++;
    	b=0;
    }
}
