#include"stdio.h"
int ans=0,i,m,n,j,entryi,entryj;
char a[100][100];
int b[100][100]={0};
void sub(int i,int j)
{
	if(ans!=0)    return ;
	if(i<0||i>n-1||j<0||j>m-1)    return ; 
	if(a[i][j]=='#')    return ;
	if(b[i][j]==1)    return ;           //此处注意把走过的路存起来，
	b[i][j]=1;                          // 以防总是走回头路陷入死循环 
	if(a[i][j]=='J')    ans=1;
	sub(i+1,j);
	sub(i-1,j);
	sub(i,j+1);
	sub(i,j-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	    scanf("%s",a[i]);
	for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
	        if(a[i][j]=='S')  
	    	{
		    	entryi=i;
		    	entryj=j; 
		    }
	sub(entryi,entryj);
	if(ans!=0)
	    printf("Happy Happy S and J\n");
	else
	    printf("MDZZ\n");
}
