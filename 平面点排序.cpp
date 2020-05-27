#include"stdio.h"
int main()
{
	int n,i,j,min;
	scanf("%d",&n);
	typedef struct m
	{
		int x,y;
		long dis;
	}point;
	point spot[1000],temp;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&spot[i].x,&spot[i].y);
		spot[i].dis=spot[i].x * spot[i].x + spot[i].y * spot[i].y;
	}
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(spot[min].dis>spot[j].dis)
			    min=j;
		if(min!=i)
		{
			temp=spot[min];
			spot[min]=spot[i];
			spot[i]=temp;
		}
	}
	for(i=0;i<n;i++)
	    printf("%d %d\n",spot[i].x,spot[i].y);
	return 0;
}
