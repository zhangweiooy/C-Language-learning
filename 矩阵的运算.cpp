#include<stdio.h>
int main()
{
	int n1,m1,n2,m2,i,jj,j,judge=0,s=0;
	int a[100][100],b[100][100],c[100][100];
	while(scanf("%d%d",&n1,&m1)!=EOF)
	{
		for(i=0;i<n1;i++)
	        for(j=0;j<m1;j++)
		        scanf("%d",&a[i][j]);
		scanf("%d%d",&n2,&m2);
		for(i=0;i<n2;i++)
		    for(j=0;j<m2;j++)
			    scanf("%d",&b[i][j]);
		if(m1!=n2)
		{	printf("error\n");
		    continue;
		}                   //无法相乘的情况 
		for(i=0;i<n1;i++)
		{
			for(jj=0;jj<m2;jj++)                //jj表示计算过程中b的列 
			{
			    for(j=0;j<m1;j++)
			    {
			    	s+=a[i][j]*b[j][jj];
				}
				c[i][jj]=s;
				s=0;
			}
		}
		printf("%d %d\n",m2,n1);
		for(i=0;i<m2;i++)
		{
			for(j=0;j<n1;j++)
			{
				if(judge==1) printf(" ");
			    printf("%d",c[j][i]);
			    judge=1;
			}
			printf("\n");
			judge=0;
		}
    }
}
