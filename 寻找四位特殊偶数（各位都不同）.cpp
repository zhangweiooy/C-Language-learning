#include"stdio.h"
int main()
{
	int a,b,p1,p2,p3,i=0,p4;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
	if(a==0||b==0)
	    return 0;
	if(a>999&&a<10000&&b<10000&&b>999&&a<b)
	{
		while(a<b)
		{
			p4=a%10;
			p3=a/10%10;
			p2=a/100%10;
			p1=a/1000%10;
			if(p1!=p2&&p1!=p3&&p1!=p4&&p2!=p3&&p2!=p4&&p3!=p4&&(p4%2==0))
			    {
				printf("%d  ",p1*1000+p2*100+p3*10+p4);
			    i++;
				}
			a++;    
		}
		printf("\n");
		printf("counter=%d\n",i); 
		i=0;
	}
	else printf("Error\n");
	}
	return 0;
}
