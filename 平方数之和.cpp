#include"stdio.h"
#include"math.h"
int square(int i)
{
	int j;
	for(j=1;j<sqrt(i)+2;j++)
	    if(j*j==i)
	        return 1;
	return 0;
}
int main()
{
	int ans=0,i,m,n;
	scanf("%d,%d",&m,&n);
	for(i=m;i<=n;i++)
	{
		if(square(i))
		    ans+=i;
		else  continue ;
	}
	printf("%d\n",ans);
}
