#include"stdio.h"
int main()
{
	int a,b,c,y;
	k:while(scanf("%d%d",&a,&b)!=EOF)
	{
	if(a<b)
	   {
		c=a;
		a=b;
		b=c;
	   }
	if(a==0||b==0)
	{
	    if(a==0)
	      {printf("%d\n",b);
	       goto k;
		  }
	    else {printf("%d\n",a);
	          goto k;
		     }
	}
	for(y=1;y!=0;)
	  {
	  	y=a%b;
	  	a=b;
	  	b=y;
	  }
	printf("%d\n",a);
	
    }
}
