#include"stdio.h"
int main()
{
	int t,m,n1,n,n5,n10,n20,n50,a,n100,k1,k20,k5,k10,k50,k100;

	scanf("%d\r",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d",&m,&n1,&n5,&n10,&n20,&n50,&n100);
		k100=m/100;
		if(k100>n100)
		
			k100=n100;
			m=m-k100*100;
		
		k50=m/50;
		if(k50>n50)
		
			k50=n50;
			m=m-k50*50;
		
		k20=m/20;
		if(k20>n20)
		
			k20=n20;
			m=m-k20*20;
		
		k10=m/10;
		if(k10>n10)
		
			k10=n10;
			m=m-k10*10;
		
		k5=m/5;
		if(k5>n5)
		
			k5=n5;
			m=m-k5*5;
		
		k1=m/1;
		if(k1>n1)
		{
			printf("poor BOSS Lei\n");
		}
		else {
			printf("%d\n",k100+k50+k20+k10+k5+k1);
			printf("%d %d %d %d %d %d\n",k1,k5,k10,k20,k50,k100);
		}
	}
}
