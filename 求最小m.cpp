#include"stdio.h"
int main()
{
	long s=1,m=0,n;
	scanf("%ld",&n);
	while(s<n)
    {
    	m++;
		s=m*(m+1)/2;
    	
	}
	printf("%ld",m);
}
