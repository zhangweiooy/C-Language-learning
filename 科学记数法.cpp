#include"stdio.h"
#include"string.h" 
int main()
{
	char temp[10000],a[10000]={'\0'};
	int i=0,j=0,k,assist=-30000,judge2=0,judge=0,n=0,flag=0;
	gets(temp);
	while(1)
	{
		if(temp[i]>='0'&&temp[i]<='9')
		{
			a[j]=temp[i];
			j++;
		}
		if(temp[i]=='.')
		{
			assist=i;
			judge2=1;
		}
		if(temp[i]==' ')
		    break ;
		i++;
	}
	for(i=(temp[0]=='-'?strlen(a)+2:strlen(a)+1) ; temp[i]!='\0';i++)
	{
		if(temp[i]==' '||temp[i]=='e'||temp[i]=='E')
		    continue ;
		if(temp[i]=='-')
		    flag=1;
		if(temp[i]>='0'&&temp[i]<='9')
		    n=n*10+temp[i]-'0';
	}
	if(temp[0]=='-')
	    assist-=1;
	if(flag==1)
	    n=-n;
	assist+=n;
	if(judge2==0)
	    assist=strlen(a)+n;
	if(assist<=0)
	{
		if(temp[0]=='-')
		{
			printf("-");
			
		}
		printf("0.");
		k=0;
		while(assist<0&&k<8)
		{
			printf("0");
			assist++;
			k++;
		}
		for(j=0;a[j]!='\0'&&k<8;k++,j++)
		    printf("%d",a[j]-'0');
		while(k<8)
		{
			printf("0");
			k++;
		}
	}
	if(assist>0)
	{
		if(temp[0]=='-')
		{
			printf("-");
		}
		for(j=k=0;a[j]!='\0'&&k<8;j++)
		{
			if(j==assist)
			{
				printf(".");
				judge=1;
			}
			printf("%d",a[j]-'0');
			if(judge==1)
			    k++;
		}
		while(j<assist)
		{
			printf("0");
			j++;
		}
		if(j==assist)
		{
			printf(".");
			judge=1;
		}
		while(k<8)
	    {
	    	printf("0");
	    	k++;
		}
	}
	
	printf("\n");
	return 0;
 } 
