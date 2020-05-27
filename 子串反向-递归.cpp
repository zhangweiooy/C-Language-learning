#include <stdio.h>  
#include <stdlib.h>  
void reverse(char a[],int i,int j)
{
	int x=0;
	char b;
	
k:	if(i>=j)    
	    return ;
	x++;
	if(a[x]!='\0')
	    goto k;
	if(i>=x-1)    i=x-1;
	if(j>=x-1)    j=x-1;
	b=a[i];
	a[i]=a[j];
	a[j]=b;
	reverse(a,i+1,j-1);
}
int main( )  
{   char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse(str,start,end);  
    printf("%s\n", str);  
    return 0;  
}  

