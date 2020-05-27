#include"stdio.h"
#include"math.h"
int main()
{
	int a[12],i,m,n,assist;

	scanf("%d",&a[0]);
	scanf("%d",&assist);
	for(i=4;i>=0;i--)
	{
		a[5-i]=assist/pow(10,i);
		assist=assist-a[5-i]*pow(10,i);
	}
    scanf("%d",&assist);
    for(i=4;i>=0;i--)
    {
    	a[10-i]=assist/pow(10,i);
    	assist=assist-a[10-i]*pow(10,i);
	}
	m=a[0]+a[2]+a[4]+a[6]+a[8]+a[10];
	n=a[1]+a[3]+a[5]+a[7]+a[9];
	a[11]=9-((m*3+n-1)%10);
	printf("%d\n",a[11]);
}
