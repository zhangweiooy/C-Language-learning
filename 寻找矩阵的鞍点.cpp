#include <stdio.h>
int main( ) 
{
	int i,j,m,n;
	int max=0,judge,jmax,judge2=0;
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<m;i++) 
	{
		max=a[i][0];
		jmax=0;
		for(j=1; j < n;j++) 
		{                            // �ҳ�i������
			if(max < a[i][j]) 
			{
				max = a[i][j];
				jmax = j;                              // �Ҽ�¼���ڵ�������
			}
		}
		judge=1;
		for(j = 0; j < m ;j++)
		{                                           // �ж�max�Ƿ�Ϊ��������С��
			if(a[j][jmax] < max)         
				judge=0;         
		}
		if(judge!=0) 
		{
			printf("Point:a[%d][%d]==%d\n",i,jmax,max);
			judge2=1;
		}
		judge=0; 
	}
	if(judge2==0) 
	    printf("No Point\n");
	return 0;
}

