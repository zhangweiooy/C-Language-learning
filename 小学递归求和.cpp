#include"stdio.h"
int s=0;
int digital(int i,int j)
{
	s+=i;
	if(i==j)
	    return s;
	digital(i+1,j); 
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	digital(n,m);
	printf("The sum from %d to %d is %d.\n",n,m,s);
}
