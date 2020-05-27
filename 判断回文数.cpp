#include"stdio.h"
int main()
{
	int n,a,b=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(a=n;a>0;)
		{
			b=b*10+a%10;
			a=a/10;
		}
		if(b==n)
		   printf("YES\n");
		else printf("NO\n");
		b=0;
	}
}
