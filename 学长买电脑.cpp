#include"stdio.h"
int count=0;
void sub(int i)
{
	count++;
	int j;
	if(i==0)
	    return ;
	else
	    for(j=i/2;j>0;j--)
	        sub(j);
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
    sub(n);
	printf("%d\n",count);
}
