#include"stdio.h"
#include"string.h"
char mine[100][100];
int count=1;
void sub(int n,int m,char mine[100][100]);
int main()
{
	
	int n,m,i,j;
fuck:
	
	scanf("%d%d",&n,&m);
    getchar();
	if(m==0&&n==0)
	    return 0;
	if(count>=2)
	    printf("\n");
	for(i=0;i<n;i++)
	    gets(mine[i]);
	printf("Field #%d:\n",count);

	sub(n,m,mine);
	count++;
	goto fuck;
}
void sub(int n,int m,char mine[100][100])
{
	int k=0,i,j,ii,jj;
	char ans[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mine[i][j]=='*')
			    ans[i][j]='*';
			else
			{
			    for(ii=(i==0?0:i-1);ii<=(i==n-1?n-1:i+1);ii++)
			    {
		    		for(jj=(j==0?0:j-1);jj<=(j==m-1?m-1:j+1);jj++)
			     	{
			    		if(mine[ii][jj]=='*')
			    		    k++;
			    	}
		    	}
		    ans[i][j]=k+48;
		    }
		    
		    k=0;
		}
	}
	for(i=0;i<n;i++)
	{
	    for(j=0;j<m;j++)
	        printf("%c",ans[i][j]);
	    printf("\n");
    }
   
	return ;
}
