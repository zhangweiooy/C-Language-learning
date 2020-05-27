#include"stdio.h"
#include"string.h"
char a[1000]={'\0'};
int judge(int n)
{
	if(n==(strlen(a)%2==0?strlen(a)/2:strlen(a)/2+1))
    {
    	if(a[n]==a[strlen(a)-1-n])
    	    return 1;
	}
	if(a[n]!=a[strlen(a)-1-n])
	    return 0;
	if(a[n]==a[strlen(a)-1-n])
	    return judge(n-1);
	
	
}
int main()
{
	int i;
	
	gets(a);
	i=strlen(a);
	if(a[0]=='\0')   {printf("Yes\n");return 0;}
	if(i==1)
	{ 
	    printf("Yes\n");
	    return 0;
	}
	if(judge(i-1))
	    printf("Yes\n");
	else
	    printf("No\n");
    return 0;
}
