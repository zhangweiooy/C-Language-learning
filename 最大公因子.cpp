#include"stdio.h"
#include"math.h"
int main()
{
	int i,m,max=1,n;
	scanf("%d,%d",&m,&n);
	for(i=1;i<=m;i++)
	{
		if(m%i==0&&n%i==0&&i>max)
		    max=i;
	}
	printf("%d\n",max);
}
