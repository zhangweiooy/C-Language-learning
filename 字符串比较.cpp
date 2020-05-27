#include <stdio.h>  
 
#define strlen      gg  
#define strcmp      gg  
#define strcpy      gg  
#define strncmp     gg  
#define strncpy     gg  
  
int my_strcmp(const char* s1, const char* s2);  
  
int main(int argc, char* argv[]) {  
    static char s1[1024];  
    static char s2[1024];  
    gets(s1);  
    gets(s2);  
  
    int cmp = my_strcmp(s1, s2);  
    if (cmp > 0)  
        puts(">");  
    else if (cmp == 0)  
        puts("=");  
    else  
        puts("<");  
    return 0;      
}  
int my_strcmp(const char* s1, const char* s2)
{
    
	while(*s1 == *s2)
    {
        if(*s1 == '\0'&&*s2 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
