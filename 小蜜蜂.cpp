#include"stdio.h"
__int128 ans=0;
int n;
void digital(__int128 i,__int128 j)
{
	ans=i+j;
	n--;
	if(n==0)    return ;
	digital(j,ans);
}
void output(__int128 v, char s[])  
{  
    char temp;  
    int i=0, j;  
    while(v >0) 
	{  
        s[i++] = v % 10 + '0';  
        v /= 10;  
    }  
    s[i] = '\0';  
    j=0;  
    i--;  
    while(j < i) 
	{  
        temp = s[j];  
        s[j] = s[i];  
        s[i] = temp;  
        j++;  
        i--;  
    }  
}  
int main()
{
	int a,b;
	char s[128];
	scanf("%d%d",&a,&b);
	n=b-a+1;
	if(n<=2)
	{
		printf("1\n");
		return 0;
	}
	else    n=n-2;
	digital(1,1);
	output(ans,s);
	puts(s);
}
