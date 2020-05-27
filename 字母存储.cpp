#include"stdio.h"
#include"stdlib.h"
int main()
{
	char a[]={"abcdcba"};
	int n,i;
	scanf("%c",&n);
	if(n>='7'&&n<'a'){
		printf("N\n");
	}
	if(n<'7'&&n>='0')
	{
		printf("%c\n",a[n-'0']);
	}
	if(n>='a'&&n<='z')
	{
		for(i=6;i>=0;i--)
		    if(a[i]==n)
		    {
		    	printf("%d\n",i);
		    	break ;
			}
	}
	return 0;
}
