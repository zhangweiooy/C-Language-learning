#include"stdio.h"
int main()
{
	int n,a[22],l,r,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	l=0;
	r=n-1;
	while(l<=r)
	{
		if(l!=r)
			printf("%d ",a[l++]*a[r--]);
		else
		    printf("%d ",a[l++]);
	}
	printf("\n");
	return 0;
 } 
