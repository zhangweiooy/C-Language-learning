#include<stdio.h>
int main()
{
	int a=1,b=1,c=1,n,i=0;
	scanf("%d",&n);
	while(c<=n)
	{
	    while(b<=c)
	    {
		    while(a<=b)
		    {
			    if((a*a+b*b)==c*c)
			    {
				    i++;
			    }
			    a++;
		    }
		    b++;
		    a=1;
	    }
	    c++;
	    b=1;
	    a=1;
    }
	printf("%d",i);
}
