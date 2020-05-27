#include"stdio.h"
int main()
{
	int n,t,i;
	int min;
	int day[200000]={0};
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{ 
	    	scanf("%d",&t);
    		day[t]=i+1;
			min=t;
		}
    	for(i=0;i<n;i++)
		{
	    	if(day[i]==0)
	    		continue;
    		if(day[min]>day[i])
			{
				day[min]=0;
				min=i;
			}
			else
			{
				if(min!=i)
					day[i]=0;
			}
		} 
		day[min]=0;
    	printf("%d\n",min);
	}
	return 0;
}
