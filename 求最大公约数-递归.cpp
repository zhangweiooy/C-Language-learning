#include"stdio.h"
int GCD(int dividend,int divisor)
{
	if(dividend%divisor==0)
	    return divisor;
	if(dividend%divisor!=0)
	    return GCD(divisor,dividend%divisor);
}
int main()
{
	int n,assist, m;
	scanf("%d%d",&n,&m);
	if(n<m)
	{
		assist=m;
		m=n;
		n=assist;
	}
	printf("%d\n",GCD(n,m));
}
