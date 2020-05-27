#include"stdio.h"

double figure(int n)
{
	if(n==1)
	{
		return 1;
	}
	if(n%2==0)
	    return 1/(n*1.0)+figure(n-1);
	if(n%2==1)
	    return -1/(n*1.0)+figure(n-1);
	
}
int main()
{
	int n;
	
	scanf("%d",&n);
	if(n==1)
	    printf("%d\n",n);
	else
	    printf("%.6lf\n",figure(n));
	return 0;
}
