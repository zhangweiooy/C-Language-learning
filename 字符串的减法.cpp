#include"stdio.h"
int main()
{
	int i,j,judge=1,k=0;
	char s[100],t[100],u[100];
	gets(s);
	gets(t);
	for(i=0;s[i]!='\0';i++)
	{
		for(j=0;t[j]!='\0';j++)
		{
			if(s[i]==t[j])
			    judge=0;
		}
		if(judge==1)
		{
		    u[k]=s[i];
		    k++;
	    }
	    judge=1; 
	}
	u[k]='\0';
	puts(u);
}
