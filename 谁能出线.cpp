#include"stdio.h"
int main()
{
	int max,a[12],i;
	for(i=1;i<=10;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)  max=a[i];
		if(a[i]>max)  max=a[i];
	}
	for(i=1;i<=10;i++)
	{
		if(a[i]==max)
		    printf("%d\n",i);
	}
	return 0;
}
