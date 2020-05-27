#include"stdio.h"
int main()
{
	int n,k,sub1,sub2,sub3;
	char s[5];
	scanf("%d",&k); 
	for(n=10000;n<=30000;n++)
	{
		sprintf(s,"%d",n);
		sub1=(s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0';
		sub2=(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
		sub3=(s[2]-'0')*100+(s[3]-'0')*10+s[4]-'0';
		if(sub1%k==0&&sub2%k==0&&sub3%k==0)
		     printf("%d\n",n);
	}
 } 
