#include"stdio.h"
#include"stdlib.h"
int cmp(const void*e1,const void *e2)
{
	return *(int*)e2-*(int*)e1;
}
int main()
{
	int i,j,k,n;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	if(k>n)
	    printf("-1\n");
	else
	printf("%d %d\n",a[k-1],a[k-1]);
	return 0;
 } 
