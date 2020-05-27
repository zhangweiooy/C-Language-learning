#include"stdio.h"
#include"math.h"
int main()
{
	int n,a,b,c,d=0,m;
	scanf("%d",&n);
	m=pow(10,(n-1));
	while(m<pow(10,n))
	{
		b=0;
		c=m;
		while(c>0)
		{
			a=c%10;
			c=c/10;
			b=b+pow(a,n);
		}
		if(b==m)
		{
			printf("%d\n",b);
			d=d+1;
		}
		m++;
	}
	if(d==0)
	    printf("No output.\n");
}
