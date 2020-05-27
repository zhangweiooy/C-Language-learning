#include"stdio.h"
int main()
{
	int n,i,j,k;
	char ch;
    scanf("%c,%d",&ch,&n);
    if(n==1)
	    {
		printf("%c\n",ch);
		return 0;
		}                                       //一的特殊情况 
	for(i=1;i<n;i++)
    {
    	printf(" ");
	}
	printf("%c\n",ch);                //第一行
	ch++;
	if(ch=='Z'+1)
	    ch='A';
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}                               //前半部分 
		printf("%c",ch);
		
		for(j=1;j<=2*i-3;j++)
		{
			printf(" ");
		}
		printf("%c\n",ch);               //中间及后部 
		ch++;
	    if(ch=='Z'+1)
	        ch='A';
	}                                                      //上半部分
	ch--;
	if(ch=='A'-1)
	    ch='Z';
	ch--;
	if(ch=='A'-1)
	    ch='Z';
	for(;i<=2*n-2;i++)
	{
	    for(j=1;j<=i-n;j++)
		    printf(" ");
		printf("%c",ch);
	
		for(j=1;j<=4*n-3-2*i;j++)
		    printf(" ");
		printf("%c\n",ch);
		ch--;
	    if(ch=='A'-1)
	        ch='Z';
	}                                            //下半部分
	for(i=1;i<n;i++)
    {
    	printf(" ");
	}
	printf("%c\n",ch);                      //最后一行 
}
