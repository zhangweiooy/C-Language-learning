#include"stdio.h"
#include"math.h"
int main()
{
	double x1,x2,a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0)
	    {
		if(b==0)
	        printf("Input error!\n");
	    else if(c==0)
		         printf("x=%.6lf\n",c/b);
		     else printf("x=%.6lf\n",-c/b);    
		}
	else if(b*b-4*a*c>=0)
	         {
			 x1=(-b+sqrt(b*b-4*a*c))/2/a;
			 x2=(-b-sqrt(b*b-4*a*c))/2/a;
			 if(x1==x2)
			    {
				printf("x1=x2=%.6lf\n",x1);
			    return 0;}
			 printf("x1=%.6lf\n",x1);
	         printf("x2=%.6lf\n",x2);
			 }

	if(b*b-4*a*c<0)   
		   {
			 if(b==0)
			      {
	              	 x1=(-b+sqrt(4*a*c-b*b))/2/a;
	              	 x2=(-b-sqrt(4*a*c-b*b))/2/a;
	                 printf("x1=%.6lfi\n",x1);
	                 printf("x2=%.6lfi\n",x2);
	           	  }
			  else 
			  {
	
				printf("x1=%.6lf+%.6lfi\n",-b/2/a,sqrt(4*a*c-b*b)/2/a);
			  	printf("x2=%.6lf%.6lfi\n",-b/2/a,-sqrt(4*a*c-b*b)/2/a);
						}
		}
}
