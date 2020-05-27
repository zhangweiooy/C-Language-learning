#include<stdio.h>
main()
{
int x;
while (1)
{
printf("input number:");
scanf("%d",&x);
if (x==0) break;
if(x==1)
printf("A\n");
else 
printf("B\n");
} 
} 
