#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int len,i,j,odd=0,od[130],n[130],even[130],k,kk,kkk;
	char a[200005];
	scanf("%d\n",&len);
	memset(n,0,sizeof(n));
	gets(a);
	for(i=0;i<len;i++)
	{
		n[a[i]]++;
	}
	for(i=0,k=0,kk=0;i<130;i++)    //n的下标即为字符, n为其出现次数 
	{
		if(n[i]==0)
		    continue;
		if(n[i]%2!=0)
		{    odd++;
	         od[k]=i;
	         k++;
        }
	    else
	    {
	    	even[kk]=i;
	    	kk++;
		}
	}
	if(odd==0)
	{
		printf("0\n");
		for(i=0;i<kk;i++)
		{
			for(kkk=0;kkk<n[even[i]]/2;kkk++)
			    printf("%c",even[i]);
		}
		for(i=kk-1;i>=0;i--)
		{
			for(kkk=0;kkk<n[even[i]]/2;kkk++)
			    printf("%c",even[i]);
		}
		printf("\n");
		return 0;
	}
	printf("%d\n",odd-1);
	
	
		for(i=0;i<kk;i++)
		{
			for(kkk=0;kkk<n[even[i]]/2;kkk++)
			    printf("%c",even[i]);
		}
		for(kkk=0;kkk<n[od[0]];kkk++)
		    printf("%c",od[0]);
		for(i=kk-1;i>=0;i--)
		{
			for(kkk=0;kkk<n[even[i]]/2;kkk++)
			    printf("%c",even[i]);
		}
	
	printf("\n");
	for(i=1;i<k;i++)
	{
		for(kkk=0;kkk<n[od[i]];kkk++)
		    printf("%c",od[i]);
		printf("\n");
	}
	return 0;
}
