#include <stdio.h>  
int main()   
{  
   int n,m, count(int n,int m );  
   scanf("%d %d", &n,&m);  
   printf("%d\n", count (n, m));    
   return 0;  
}  

int count( int n, int m )   
{
	int s;
	if(n<1||m<1)
	    return 0;
	if(n==1||m==1)
	    return 1;
	if(n<=m)
	    s=count(n,m-1)+1;
	if(n>m)
	    s=count(n-m,m)+count(n,m-1);
    return s;
}    

