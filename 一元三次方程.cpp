#include"stdio.h"
#include"math.h"
int main()
{
	int t,root=0;
	double x1,x2,y1,y2,a,b,c,d,y0,top;
	const double eps = 1e-8;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		if(a==0)
		{
			if(b==0)
			{
				if(c==0)
				{
					if(d==0)
					{
						root=4;
						goto k;
					}
					goto k;
				}
				root=1;
				goto k;
			}
			if(c*c-4*b*d>0)
                root=2;
            if(c*c-4*b*d==0)
                root=1;
            goto k;
		}
		if(b*b-3*a*c<=0)
		{
			root=1;
			goto k;
		}
		y0=-b*b/(3*a)+c;
		x1=(-b-sqrt(b*b-3*a*c))/(3*a);
		x2=(-b+sqrt(b*b-3*a*c))/(3*a);
		y1=a*x1*x1*x1+b*x1*x1+c*x1+d;
		y2=a*x2*x2*x2+b*x2*x2+c*x2+d;
		
		if(y1>eps&&y2>eps||y1<-eps&&y2<-eps)
		    root=1;
		else if(y1<-eps&&y2>eps||y1>eps&&y2<-eps)
		    root=3;
		else
		    root=2;
	    k:	
	    if(root>3)
		    printf("Impossible!\n"); 
		else
		    printf("%d\n",root);
		root=0;
	}
	return 0;
}
