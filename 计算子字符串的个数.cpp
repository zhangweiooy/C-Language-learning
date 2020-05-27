#include <stdio.h>

int countsub( char *str, char *ss );

main( )
{
    char s1[1000] = {0}, s2[100] = {0};
    gets(s1);
    gets(s2);
    printf("%d\n", countsub( s1, s2 ) );
}
#include"string.h" 
int countsub( char *str, char *ss )
{
	int i,j,judge,k,s=0,count=0;
	for(i=0;i<strlen(str);i++)
	{
		judge=1;
		if(*(str+i)==*(ss))
		{
		    for(j=k=0;str[k]!='\0';k++)
		    {
			    if(*(str+i+k)!=*(ss+j))
			    {
			    	s=judge=0;
			    	break ;
				}    
				j++;
				if(j==strlen(ss))
				{
					j=0;
					s++;
				}
				if(s>count)
			    count=s; 
		    }
	           
		}
	}
	return count;
}
