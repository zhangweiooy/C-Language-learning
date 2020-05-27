#include"stdio.h"
int main()
{
	char a[1020];
	int i,j=0,judge;
	while(gets(a))
	{
		j=judge=0;
		for(i=0;a[i]!='\0';i++)
		{
			
			
			if(a[i]>'0'&&a[i]<='9'&&judge==0)
		    {
		    	if(j==1) printf(" ");
				printf("%c",a[i]);
		    	judge=1;
		    	if(a[i+1]<'0'||a[i+1]>'9')
				    {judge=0;
				     j=1;
				    } 
				continue;
			}
            if(a[i]=='0'&&(a[i+1]<'0'||a[i+1]>'9')&&judge==0)
            {
		        if(j==1) printf(" ");
				printf("0");
	    		j=1;
		    }
			if(a[i]>='0'&&a[i]<='9'&&judge==1)
			{
				printf("%c",a[i]);
	
				if(a[i+1]<'0'||a[i+1]>'9')
				    {judge=0;
				    j=1;
				    } 
			}
		
		}
		printf("*\n");
	}
}
