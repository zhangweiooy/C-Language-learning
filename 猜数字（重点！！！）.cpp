//关于此题，可发现这组数字的规律：在第n行出现的数字的二进制
//     形式的第n位都是1，而其余位是0，因此得出结果。 
#include"stdio.h"
#include"math.h"
int main()
{
	int a[10]={1},i,assist,n=0;
	for(i=1;a[i-1]!=0;i++)
	{
		scanf("%d",&a[i]);
	}
	assist=i-2;
	for(i=1;i<=assist;i++)
	{
		n=n+pow(2,(a[i]-1));
	}
	printf("%d\n",n);
}
