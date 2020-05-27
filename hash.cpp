#include"stdio.h"
#include"string.h"
long pow(long a,long b)
{
    int r=1,base=a;
    while(b)
	{
        if(b&1) r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,n,i,j;
		scanf("%d",&k);
		long b,m,ans[k];
		scanf("%ld %ld\n",&b,&m);
		char s[k][1003];
		for(j=0;j<k;j++)
		    gets(s[j]);
		
		for(j=0;j<k;j++)
		{
			n=strlen(s[j]);
			for(i=0;i<n;i++)
			{
				ans[j]+=(s[j][i]*pow(b,n-i-1))%m;
			}
		}
		for(j=0;j<k;j++)
		    printf("%ld ",ans[j]);
	}
	return 0;
}
