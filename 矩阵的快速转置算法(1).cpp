#include<stdio.h>
typedef struct point
{
	int r,c,val;
} point;
point points[1000];
void change(int no,int n)
{
	int num[no+1];
	int cpot[no+1];
	int order[n+1];
	for(int i=1;i<=no;i++)
	    num[i]=0;
	cpot[0]=1;cpot[1]=1;
	for(int i=1;i<=n;i++)
	    num[points[i].r]++;
	for(int i=1;i<no;i++)
	    cpot[i+1]=cpot[i]+num[i];
	for(int i=1;i<=n;i++)
	{
		order[cpot[points[i].r]]=i;
		cpot[points[i].r]++;
	}
	
	
	printf("num:");
	for(int i=1;i<=no;i++)
	    printf("%d,",num[i]);
	printf("\ncpot:");
	for(int i=0;i<no;i++)
	    printf("%d,",cpot[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
	    printf("%d,%d,%d\n",points[order[i]].r,points[order[i]].c,points[order[i]].val);
}
int main()
{
	int col,row,n;
	scanf("%d%d%d",&row,&col,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&points[i].c,&points[i].r,&points[i].val);
	}
	change(col,n);
	
}
