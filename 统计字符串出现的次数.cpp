#include"stdio.h"
#include"string.h"
int main()
{
	int m,n,i,j,count=0;
	char a[1000],b[100];
	gets(a);
	gets(b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m-n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i+j]!=b[j])
			    break;
			if(j==n-1)
			    count++;
		}
	}
	if(count>0)
	    printf("%d\n",count);
	else
	    printf("No\n");
	return 0;
 } 
