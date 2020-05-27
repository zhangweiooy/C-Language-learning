#include"stdio.h"
int main()
{
	int temp,i,j=0,a[7][2],sum[7],judge=0;
	for(i=0;i<7;i++)
	{
	    scanf("%d %d",&a[i][0],&a[i][1]);
	    sum[i]=a[i][0]+a[i][1];
	}
	temp=sum[0];
	for(i=1;i<7;i++){
		if(sum[i]>temp&&sum[i]>=10)
			{
				judge=1;
				temp=sum[i];
				j=i;
				}    
	}
	if(judge==1)
	   printf("%d\n",j+1);
	else if(sum[0]>=10)
	        printf("1\n");
         else
		    printf("0\n");	   
	return 0;
 } 
