#include"stdio.h"
int ans;
int fun(int i)
{
	if(i==7)
	    return 4;
	ans=(fun(i+1)-1)*2+2;
}
int main()
{
	int j;
	printf("sum=%d\n",(fun(1)-1)*2);
	for(j=1;j<=7;j++)
	{
		if(j==7)
		    printf("sell=%d,\n",fun(j));
		else
		    printf("sell=%d,",fun(j));
	}
	return 0;
}
