#include"stdio.h"
void sort(long d[],int n)
{
	int i,min,j;
	long assist;
	for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			    if(d[min]>d[j])
			        min=j;
			if(min!=i)
			{
			    assist=d[min];
			    d[min]=d[i];
			    d[i]=assist;
			}	
		}
	return ;
}
int main()
{
	int n,i,judge=1;
	scanf("%d",&n);
	long d[n];
	for(i=0;i<n;i++)
	    scanf("%ld",&d[i]);
	sort(d,n);
	for(i=0;i<n;i++)
		if(d[i]<i+1)
		{
			judge=0;
			break ;
			}    
	if(judge==1)
	    printf("YES\n");
	if(judge==0)
	    printf("NO\n");
	return 0;
 } 
