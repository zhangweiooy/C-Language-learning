#include"stdio.h"
int main()
{
	int t,i,j,k,judge=1;
	char a[9][9],temp;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		for(i=0;i<9;i++)
		    scanf("%s",a[i]);
		for(i=0;i<9;i++)
		    for(j=0;j<9;j++)
		   	{
			   temp=a[i][j];
			   for(k=j+1;k<9;k++)
			       if(a[i][k]==temp)
			           judge=0;
		    }
		for(j=0;j<9;j++)
		    for(i=0;i<9;i++)
		    {
		    	temp=a[i][j];
		    	for(k=i+1;k<9;k++)
		    	    if(a[k][j]==temp)
		    	        judge=0;
			}
		if(judge==1)
		    printf("Accepted\n");
		if(judge==0)
		    printf("Rejected\n");
		judge=1;
	}
	return 0;
}
