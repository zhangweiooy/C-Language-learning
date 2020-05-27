#include<stdio.h>
#include <math.h>
int main()
{
int i,j,k,h,m;
scanf("%d",&h);
for(i=1;i<=h;i++)
{
for(j=1;j<=(h-i)*2;j++)
printf(" ");
for(j=1,k=1,m=1;j<=2*i-1;j++)
if (k<=i)
printf("%2d",k++),m++;
else
printf("%2d",--m-1);
printf("\n");
}
return 0;
}
