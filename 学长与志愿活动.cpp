#include"stdio.h"
void sort(long d[][2],int n)
{
	int i,min,j;
	long assist1,assist0;
	for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			    if(d[min][1]>d[j][1])
			        min=j;
			if(min!=i)
			{
			    assist0=d[min][0];
			    assist1=d[min][1];
			    d[min][0]=d[i][0];
			    d[min][1]=d[i][1];
			    d[i][0]=assist0;
			    d[i][1]=assist1;
			}	
		}
	return ;
}
int main()
{
	int n,i,j,count=0;
	long a[1000][2],b1=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    for(j=0;j<2;j++)
	        scanf("%ld",&a[i][j]);
	sort(a,n);
	for(i=0;i<n;i++)
	{
		if(a[i][0]>b1)
		{
			count++;
			b1=a[i][1];
		}
	}
	printf("%d\n",count);
	return 0;
 } 
