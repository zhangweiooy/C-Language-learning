#include"stdio.h"
#include"string.h" 
int main()
{
	int i,judge=0,n=0,j;
	char a[100],k,b[100]={'0'};
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		judge=0;
		k=a[i];
		for(j=0;j<i;j++)
		{
			if(k==a[j])
			    judge=1;
		}
		if(judge==0)
		{
		    b[n]=k;
		    n++;
		}
	}
	puts(b);
	return 0;
}
