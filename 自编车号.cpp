#include"stdio.h"
#include"string.h"
#include"ctype.h" 
int main()
{
	char a[5];
	int i,judge=0;
	scanf("%s",a);
	for(i=0;i<5;i++)
	{
		if(a[i]>='A'&&a[i]<='Z'&&a[i]!='I'&&a[i]!='O')
		    judge++;
	}
	if(isdigit(a[4])&&judge==2)
	{
		printf("ok.\n");
		return 0;
	}
	else
	    printf("no.\n");
	return 0;
}
