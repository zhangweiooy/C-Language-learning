#include"stdio.h"
#include"string.h"
#include"math.h"
long int trans(char a[],int d)
{
	int k,ii;
	long num;
	num=0;
	for(ii=0,k=strlen(a)-1;k>=0;k--,ii++)
	{
		if(a[ii]>='A'&&a[ii]<='Z')
		{
			num+=(a[ii]-55)*pow(d,k);
		}
		else
		    num+=(a[ii]-'0')*pow(d,k);
	}
	return num;
}
int max(char b[])
{
	int max,assist;
	max=0;
	for(assist=0;assist<strlen(b);assist++)
	{
		if(max<(b[assist]>='A'&&b[assist]<='Z'?b[assist]-55:b[assist]-'0'))
		max=(b[assist]>='A'&&b[assist]<='Z'?b[assist]-55:b[assist]-'0');;
	}
	return max;
}
int main()
{
	int i,j;
	long ans1,ans2;
	char m[30],n[30];
	scanf("%s",m);
	scanf("%s",n);
	for(i=max(m)+1;i<=36;i++)
	{
		ans1=trans(m,i);
		for(j=max(n)+1;j<=36;j++)
		{
			ans2=trans(n,j);
			if(ans1==ans2)
			{
				printf("%s (base %d) = %s (base %d)\n",m,i,n,j);
				return 0;
			}
		}
	}
	printf("%s is not equal to %s in any base 2..36\n",m,n);
	return 0;
}
