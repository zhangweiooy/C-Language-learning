#include"stdio.h"
#include"string.h"
#include"math.h"
int main()
{
	int i,j,ans;
	char n[10000];
	long t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",n);
		ans=1;
		if(strlen(n)==1)
		{
			ans=pow(5,n[0]-'0');
			if(ans>1000)
			    ans=ans%1000;
		}
		if(strlen(n)>1)
		{
			if((n[strlen(n)-1]-'0')%2==0)
			    ans=625;
			else
			    ans=125;
		}
		printf("%03d\n",ans);
	}
	return 0;
}
