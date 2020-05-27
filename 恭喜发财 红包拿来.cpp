#include"stdio.h"
#include"string.h"
int main()
{
	int n,i,ii,j,k=0;
	char temp[15];
	typedef struct m
	{
		char name[15];
		int income,count,expend;
	}chart;
	chart a[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%s",a[i].name);
        a[i].income=0;   a[i].count=0;   a[i].expend=0;	
	}
	while(1)
	{
		scanf("%s",temp);
		for(i=0;i<n;i++)
		{
			if(strcmp(temp,a[i].name)==0)
			{
				j=i;break ;
			}
		}
		scanf("%d %d",&a[j].expend,&a[j].count);
		k++;
		if(a[j].count==0)
		{
			a[j].expend=0;
			if(k==n)
		        break;
			continue ;
		}
		for(i=0;i<a[j].count;i++)
		{
			scanf("%s",temp);
			for(ii=0;ii<n;ii++)
		    {
			    if(strcmp(temp,a[ii].name)==0)
			    {
				    a[ii].income+=a[j].expend/a[j].count;
			    }
		    }
		}
		a[j].expend=a[j].expend - a[j].expend%a[j].count;
		if(k==n)
		    break;
	}
	for(i=0;i<n;i++)
	{
		printf("%s",a[i].name);
		printf(" %d\n",a[i].income-a[i].expend);
	}
	return 0;
}
