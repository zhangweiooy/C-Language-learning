#include"stdio.h"
int main()
{
	int a,b=0,c,d;
	scanf("%d",&a);
	c=a-1601;
	while(a>1601)
	{
	    if((a%4==0&&a%100!=0)||a%400==0)
	     b=b+1;
	 a=a-1; 
    }
	d=c*365+b;      //输入年份的5.1与1601年5.1（周二）相差天数
	switch(d%7)
	{
		case 0:printf("13\n");break;
		case 1:printf("12\n");break;
		case 2:printf("11\n");break;
		case 3:printf("10\n");break;
		case 4:printf("9\n");break;
		case 5:printf("8\n");break;
		case 6:printf("14\n");break;
	}
	
}
