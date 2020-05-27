#include "stdio.h"
float s=0.0;
void f(float i)
{
	s+=1/i;
	if(i==1)    return ;
    f(i-1);
    return ;
}
int main()
{
    int n;
	scanf("%d",&n);
	f(n);
	printf("sum=%f\n",s);
	return 0;
 } 
