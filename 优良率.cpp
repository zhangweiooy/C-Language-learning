#include"stdio.h"
int main()
{
	float n,i,j,a=0,rate;
	while(scanf("%f",&n)!=EOF)
	{
		scanf("\r");
		for(i=n;i>=1;i--)
		{
			scanf("%f",&j);
			if(j>=80)
			    a++;
		}
		rate=a/n*100;
		printf("%.2f%%\n",rate);
		a=0;
	}
}
