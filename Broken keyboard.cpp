#include<stdio.h>
#include<string.h>

int main()
{
	int i,len;
	char a[100002],temp[100002];
	while(scanf("%s",a)!=EOF)
	{
		for(i=0;i<100002;i++)
		    temp[i]='\0';
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='['||a[i]==']')
			    temp[i]='\0';
			else
			    temp[i]=a[i];
		}
		for(i=len-1;i>=0;i--)
		{
			if(a[i]=='[')
			    printf("%s",temp+i+1);
		}
		if(a[0]!='['&&a[0]!=']')
		    printf("%s",temp);
		for(i=1;i<len;i++)
		    if(a[i]==']')
		        printf("%s",temp+i+1);
		printf("\n");
	}
	
	return 0;
}
