#include"stdio.h"
#include"string.h"
int main()
{
	int t,i,s,judge1=0,judge2=0,judge3=0,judge4=0;
	char a[30];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		s=judge1=judge2=judge3=judge4=0;
		gets(a);
		if(strlen(a)<6)
		    judge1=0;
		else
		{
			for(i=0;(i<strlen(a))&&a[i]!='\0';i++)
		    {
		    	if(a[i]<='9'&&a[i]>='0')
		    	{
				    judge1=1;
	                continue;
			    }
			    if(a[i]<='Z'&&a[i]>='A')
		    	{
				    judge2=1;
	                continue;
			    }
			    if(a[i]<='z'&&a[i]>='a')
		    	{
				    judge3=1;
	                continue;
			    }
			    if(a[i]<'0'||(a[i]>'9'&&a[i]<'A')||(a[i]>'Z'&&a[i]<'a')||a[i]>'z')
		    	{
				    judge4=1;
	                continue;
			    }
			}
		}
		s=judge1+judge2+judge3+judge4;
		if(s<=1)
		    printf("Not Safe\n");
		else if(s==2)
		         printf("Medium Safe\n");
		     else if(s>=3)
		              printf("Safe\n");
	}
}
