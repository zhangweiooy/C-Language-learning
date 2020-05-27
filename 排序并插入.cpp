#include"stdio.h"
#include"stdlib.h"
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int a[10],i;
	for(i=0;i<8;i++)
	    scanf("%d,",&a[i]);
	scanf("%d",&a[8]);
	scanf("%d",&a[9]);
	qsort(a,10,sizeof(a[0]),cmp);
	for(i=0;i<10;i++)
	{
		if(i==9)
		    printf("%d\n",a[i]);
		else
		    printf("%d,",a[i]);
		} 
	return 0;
 } 
