#include <stdio.h>  
  
void sort_suffix(int *buffer, const char* s);  
  
int main(int argc, char* argv[]) {  
    static char s[505];  
    static int sa[505];  
      
    scanf("%s", s);  
    sort_suffix(sa, s);  
  
    for (int i = 0; s[i]; ++i)  
        printf("%d\n", sa[i]);  
    
    return 0;  
}  
#include"string.h"
void sort_suffix(int *buffer, const char* s)
{
	int min,j,i,len,temp;
	char a[1000][1000],f[1000];
	len=strlen(s);
	
    for(i=0;*s;i++)
    {
    	*buffer=i;
    	buffer++;
    	strcpy(a[i],s);
    	s++;
	}
	buffer-=i;
	
	for(i=0; i<len-1 ;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
		    if(strcmp(a[min],a[j])>0)
		        min=j;
		if(min!=i)
		{
			strcpy(f,a[i]);
			strcpy(a[i],a[min]);
			strcpy(a[min],f);
			
			temp=*(buffer+i);
			*(buffer+i)=*(buffer+min);
			*(buffer+min)=temp;
		}
	
	} 
    return ;
}

