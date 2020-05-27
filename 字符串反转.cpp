#include"stdio.h"
#include"string.h"
int main()
{
	char a[150];
	int length;
	while(scanf("%s",a)!=EOF)
	{
	    length=strlen(a);
	    while(length>0)
	    {
	    	putchar(a[length-1]);
	    	length--;
		}
	printf("\n");
	}
}
