#include"stdio.h"
int main()
{
	char ch;
	ch=getchar();
	if(ch>=65&&ch<=90)
	    ch=ch+32;
	else if(ch>=97&&ch<=122)
	        ch=ch-32;
	putchar(ch);		    
	printf("\n");    
}
