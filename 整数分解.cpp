#include<stdio.h> 
int main() 
{
    int n,i,j,m,a=0;
	scanf("%d",&n); 
	for(i=1;i<=n/2+1;i++)
	{
	    m=i;
		for(j=i+1;j<=n/2+1;j++)
		{
		    m+=j;
			if(m>=n)
			{
			    if(m==n)
				{
				    printf("%d~%d\n",i,j);
					a=1;
				}
			    break;
			}
		}
	}
	if(a==0)
	printf("None.\n");
	return 0;
}
