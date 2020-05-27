
#include<stdio.h>

typedef struct
{
	int i, j;
	int e;
}Trip;
typedef struct
{
	Trip data[1000];
	int r, c, n;
}Matrix;
int num[100] = {0};
int copt[100] = {0};
int main()
{
	Matrix m1,m2,m3;
	int k=0;
	scanf("%d%d%d",&m1.r,&m1.c,&m1.n);
	for(int x=1;x<=m1.n;x++)
		scanf("%d%d%d",&m1.data[x].i,&m1.data[x].j,&m1.data[x].e);
	scanf("%d%d%d",&m2.r,&m2.c,&m2.n);
	for(int x=1;x<=m2.n;x++)
		scanf("%d%d%d",&m2.data[x].i,&m2.data[x].j,&m2.data[x].e);
	m3.r=m1.r;m3.c=m2.c;
	for(int x=0;x<=m2.r;x++)
	    num[x]=0;
	for(int x=1;x<=m2.n;x++)
		num[m2.data[x].i]++;
	copt[0]=1;copt[1]=1;
	for(int x=2;x<=m2.r;x++)
	    copt[x]=copt[x-1]+num[x-1];
	for(int x=1;x<=m1.n;x++)
	{
		for(int y=copt[m1.data[x].j];m1.data[x].j==m2.data[y].i;y++)
		{
			Trip p;
			int flag=1;
			p.i=m1.data[x].i;
			p.j=m2.data[y].j;
			p.e=m1.data[x].e*m2.data[y].e;
			for(int z=1;z<=k;z++)
			{
				if(m3.data[z].i==p.i&&m3.data[z].j==p.j)
				{
					m3.data[z].e+=p.e;
					flag=0;
					break;
				}
			}
			if(flag)
			    m3.data[++k]=p;
		}
	}
	m3.n=0;
	for(int x=1;x<=k;x++)
	{
		if(m3.data[x].e!=0)
		    m3.n++;
	}
	printf("%d\n",m3.r);
	printf("%d\n",m3.c);
	printf("%d\n",m3.n);
	for(int x=1;x<=k;x++)
	{
		if(m3.data[x].e!=0)
		    printf("%d,%d,%d\n",m3.data[x].i,m3.data[x].j,m3.data[x].e);
	}
	return 0;
}

