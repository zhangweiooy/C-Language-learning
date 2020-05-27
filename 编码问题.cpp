#include"stdio.h"
#include"string.h"
int main()
{
	int t,n,i,j,flag=0;
	scanf("%d",&t);
	scanf("%d",&n);
	if(t==1)
	{
		int a[1005],b[1005]={0};
		for(i=0;i<n;i++)
		    scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j]<a[i])
				    b[i]++;
			}
		}
		for(i=0;i<n;i++)
        {
        	if(flag)
        	    printf(" %d",b[i]);
        	else{
        		printf("%d",b[i]);
        		flag=1;
			}
		 } 
		printf("\n");
	}
	if(t==2)
	{
		int a[1005]={0},b[1005],j,vis[1005];
		for(i=0;i<n;i++)
		    vis[i]=1;
		for(i=0;i<n;i++)
		    scanf("%d",&b[i]); 
        int s;
        for(i=n-1;i>=0;i--)
        {
        	s=0;
        	j=0;
        	while(1)
        	{
        		s+=vis[j];
        		if(s==b[i]+1)
        		{
        			a[i]=j;
        			vis[j]=0;
        			break;
				}
				j++;
			}
		}
        for(i=0;i<n;i++)
        {
        	if(flag)
        	    printf(" %d",a[i]);
        	else{
        		printf("%d",a[i]);
        		flag=1;
			}
		 } 
		printf("\n");
	}
	return 0;
}
