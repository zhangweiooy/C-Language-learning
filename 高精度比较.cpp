#include"stdio.h"
#include"string.h"
char a[10000000],b[10000000];
int main()
{
	int t,i,j,judge=2;
	
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		
		if(a[0]=='-'&&b[0]!='-')
		{
			if(a[1]=='0'&&b[0]=='0')
			{
				printf("a = b\n");
				continue;
			}
			printf("a < b\n");
		    continue;
		}
		if(a[0]!='-'&&b[0]=='-')
		{
			if(a[0]=='0'&&b[1]=='0')
			{
				printf("a = b\n");
				continue;
			}
			printf("a > b\n");
			continue;
		}
		if(a[0]=='-'&&b[0]=='-')
		{
			  
			if(strlen(a)<strlen(b))
	    	{
		        printf("a > b\n");
		        continue;
	    	}
	    	if(strlen(a)>strlen(b))
	        {
			    printf("a < b\n");
			    continue;
		    }
		    if(strlen(a)==strlen(b))
		    {
		    	if(strcmp(a,b)<0)
		    	{
		            printf("a > b\n");
		            continue;
	         	}
	         	if(strcmp(a,b)>0)
		    	{
		            printf("a < b\n");
		            continue;
	         	}
	         	if(strcmp(a,b)==0)
		    	{
		            printf("a = b\n");
		            continue;
	         	}
			}
	    }
	    if(a[0]!='-'&&b[0]!='-')
		{
	    	if(strlen(a)<strlen(b))
	    	{
	            printf("a < b\n");
		        continue;
	     	}
	     	if(strlen(a)>strlen(b))
	        {
		    	printf("a > b\n");
		    	continue;
	    	}
	    	if(strlen(a)==strlen(b))
		    {
		    	if(strcmp(a,b)<0)
		    	{
		            printf("a < b\n");
		            continue;
	         	}
	         	if(strcmp(a,b)>0)
		    	{
		            printf("a > b\n");
		            continue;
	         	}
	         	if(strcmp(a,b)==0)
		    	{
		            printf("a = b\n");
		            continue;
	         	}
			}
	    }
		
		for(i=0;i<10000000;i++)
		{
			a[i]='\0';
			b[i]='\0';
		}
	}
	return 0;
}
