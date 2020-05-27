#include"stdio.h"
#define PI 3.1415926
int main()
{
	double r,h,s,v;
	scanf("%lf",&r);
	scanf("%lf",&h);
	s=2*PI*r*h;
	v=PI*r*r*h;
	printf("s=%.2f,v=%.2f\n",s,v);
 } 
