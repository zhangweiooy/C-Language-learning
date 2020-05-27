#include"stdio.h"
#include"string.h"
int main()
{
	int i,n,j;
	char s[1000000],*str;
	
	while(scanf("%d",&n)!=EOF)
	{
		str=s;
		for(i=1;i<n*2;i++)
		{
			sprintf(str,"%d",i);
			if(i<10)
			    str+=1;
			else if(i<100)
			         str+=2;
			     else if(i<1000)
			              str+=3;
			          else if(i<10000)
			                   str+=4;
		}
		printf("%c\n",s[n-1]);
	}
}
