#include"stdio.h"
main()
{
	char ch;
	ch=getchar();
	while(ch!=EOF)
	{
	ch=ch>='A'&&ch<='Z'?ch+32:ch;
	putchar(ch);
	ch=getchar();
	}
	
}
