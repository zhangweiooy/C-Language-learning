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
		}                                       //һ��������� 
	for(i=1;i<n;i++)
    {
    	printf(" ");
	}
	printf("%c\n",ch);                //��һ��
	ch++;
	if(ch=='Z'+1)
	    ch='A';
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}                               //ǰ�벿�� 
		printf("%c",ch);
		
		for(j=1;j<=2*i-3;j++)
		{
			printf(" ");
		}
		printf("%c\n",ch);               //�м估�� 
		ch++;
	    if(ch=='Z'+1)
	        ch='A';
	}                                                      //�ϰ벿��
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
	}                                            //�°벿��
	for(i=1;i<n;i++)
    {
    	printf(" ");
	}
	printf("%c\n",ch);                      //���һ�� 
}
