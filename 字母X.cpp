#include"stdio.h"
int main()
{
	int n,i,j;
	char ch;
	scanf("%d %c",&n,&ch);
	if(ch<'A'||ch>'Z')
	{
		printf("input error.\n");
		return 0;
	}
	ch+=n-1;
	if(ch>'Z')
	ch=ch-'Z'+'A'-1;
	for(i=1;i<=n;i++)
	{
		
		for(j=1;j<=i-1;j++)
		    printf(" ");
		if(i==n)
		    goto k; 
		printf("%c",ch);
		for(j=1;j<=2*(n-i)-1;j++)
		    printf(" ");
	k:	printf("%c\n",ch);
		ch--;
		if(ch=='A'-1)
		    ch='Z';
	}                        //ÉÏ²¿ 
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-1-i;j++)
		    printf(" ");
		printf("%c",ch);
		for(j=1;j<=2*i-1;j++)
		    printf(" ");
		printf("%c\n",ch);
		ch--;
		if(ch=='A'-1)
		    ch='Z';
	}       
	return 0;
}
