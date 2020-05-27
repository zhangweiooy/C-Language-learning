#include"stdio.h"
int main()
{
	char ch;
	int n,i,j;
	scanf("%d %c",&n,&ch);
	char a[1000][2000];
	for(i=0;i<1000;i++)
	    for(j=0;j<2000;j++)
	        a[i][j]='0';
	for(j=i=0;i<n;j++,i++)
	{
		a[i][j]=ch;
		a[i][2*n-1-j-1]=ch;
		ch++;
		if(ch=='Z'+1)
		    ch='A';
	}
	i--;
	ch--;
	if(ch=='A'-1)
		    ch='Z';
	for(j=n-1;j>=0;j--)
	{
		a[i][j]=ch;
		a[i][2*n-1-j-1]=ch;
		ch++;
		if(ch=='Z'+1)
		    ch='A';
	}
	j++;
	ch--;
	if(ch=='A'-1)
		    ch='Z';
	for( ;i>0;i--)
	{
		a[i][j]=ch;
		a[i][2*n-1-j-1]=ch;
		ch++;
		if(ch=='Z'+1)
		    ch='A';
	}
	for(i=0; i<n;i++)
	{
		for(j=0; j<2*n-1;j++)
		{
			if(a[i][j]=='0')
			    printf("  ");
			else if(j!=0)
			{
				printf(" %c",a[i][j]);
			}
			else
			    printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
