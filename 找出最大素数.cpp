#include"stdio.h"
int main()
{
	int a,i,j,judge=0,s=2;
	scanf("%d",&a);
	for(j=2;j<=a;j++)
	{
		i=2;
		while(i<j)
		{
			if((j%i)!=0)
			    i++;
			else
			{
				judge=1;
				break;                 //此处勿忘加break，否则因为i没有增，会在此无限循环 
			}
		}
		if(judge==1)
		    judge=0;
		else
		    s=j;
	}
	printf("The max prime number is %d.\n",s);
}
