#include"stdio.h"
#include"string.h"
int main()
{
	int n,m,i,j,min=100,k=0,s=0,sa=0,judge=0,assist=0;
	scanf("%d%d",&n,&m);
	int a[n],b[m],c[100]={0};
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	    scanf("%d",&b[i]);
	if(m<n)
	{
		printf("bit is doomed!\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(b[j]>=a[i]&&min>b[j])
			{
				min=b[j];
				judge=1;
				assist=j;
			}
		}
		b[assist]=1000;
	    if(judge==1)
		{
		   c[k]=min;
	       k++;
	    }
	    min=100;
	    judge=0;
	}
	for(i=0;i<n;i++)
		sa=sa+a[i];
	for(i=0;i<k;i++)
		s=s+c[i];
	if(s<sa)
	{
		printf("bit is doomed!\n");
		return 0;
	}
	printf("%d\n",s);
	return 0;
}
