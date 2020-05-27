#include"stdio.h"
int main()
{
	float h,min,ha,mina,a;
	scanf("%f %f",&h,&min);
	ha=h*30+min/2;
	mina=min*6;
	a=ha-mina;
	if(a<0)
	   a=-a;
	if(a>180)
	   a=360-a;
	printf("At %.0f:%02.0f the angle is %.1f degrees.\n",h,min,a);   
	
}
