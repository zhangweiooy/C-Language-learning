#include"stdio.h"
#include<string.h>  
char a[10000][50];
int i=0;
void compress(char b[])
{
	int k,judge=0;
	char c[10000][50];
	for(k=0;k<i;k++)
	{
		if(strcmp(c[k],b)==0)
		{
			printf("%d",k+1);
			
			judge=1;
			break;
		}
	}
	if(judge==0)
	{
		   printf("%s",b);
	    if(b[0]!='\0')
	    {
	    	strcpy(c[i],b);
		    i++;
	    }
	 } 
	
	return ;
}
int main()
{
	int j=0;
	char s1;
	while((s1=getchar())!=EOF)
	{
		if(s1>='a'&&s1<='z'||s1>='A'&&s1<='Z')
		{
			a[i][j]=s1;
			j++;
		}
		else if(s1=='\0')
		{
			a[i][j]='\0';
			compress(a[i]);
			
			j=0;
			printf("\n");
		}
		else
		{
			a[i][j]='\0';
			compress(a[i]);
			j=0;
			printf("%c",s1);
		}
	}
	return 0 ;
}
