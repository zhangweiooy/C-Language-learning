#include"stdio.h"
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
	{
	
        int maxsum=0,i,flag=0;
        int sum=0;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
	    {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
	    {
	    	if(a[i]>0)  flag=1;
            sum+=a[i];
            if(sum>maxsum)
		        maxsum = sum;
		    else
			    sum=0;
    
        }
        if(flag==0) 
        {
        	maxsum=a[0];
        	for(i=1;i<n;i++)
        	{
        		if(a[i]>maxsum)
        		    maxsum=a[i];
			}
		}
        printf("%d\n",maxsum);
    }
    return 0;
}
