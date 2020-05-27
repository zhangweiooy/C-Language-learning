#include <stdio.h>
int fun(int i)
{
	int sum;
	if(i==7) sum=2;
    else sum=(fun(i+1)+1)*2;
    return sum;

}
int main() 
{
	int i;
    printf("sum=%d\n",fun(0));
    for(i=1;i<=7;i++)printf("sell=%d,",fun(i)+2);
	printf("\n");	
    return 0;
}

