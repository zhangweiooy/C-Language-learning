#include"stdio.h"
int main()
{
	int i,a[7];
	for(i=0;i<7;i++)
	    scanf("%d",&a[i]);
	printf("%d\n", (a[6]+a[5]+a[4])-(a[3]+a[2]+a[1]-a[0]) );
}
