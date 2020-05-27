#include"stdio.h"
#define PI 3.1415927
main()
{
	double r,v;
	while(scanf("%lf",&r)!=EOF)
{
	v=4*PI*r*r*r/3;
	printf("%.3lf\n",v);
}   
    return 0;
}
