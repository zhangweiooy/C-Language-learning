#include <stdio.h>  
  
   int is_palindrome(int value);  
  
   int main(int argc, char* argv[]) 
{  
    int n;  
    scanf("%d", &n);  
  
    if (is_palindrome(n))  
        puts("YES");  
    else  
       puts("NO");  
     
    return 0;  
}  
is_palindrome(int n)
{
	int a,b=0,c;
	for(a=n;a>0;)
	{
		b=b*10+a%10;
		a=a/10;
	}
	if(b==n)
	   c=1;
	else c=0;
	return c;
}

