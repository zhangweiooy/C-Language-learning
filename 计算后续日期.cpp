#include"stdio.h"
int main()
{
	int year,month,day,n,a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d%d%d",&year,&month,&day);
	scanf("%d",&n);
	day=day+n;
	if(((year%4==0&&year%100!=0)||year%400==0)&&month<=2)
	{
		a[1]=29;
	}
	while(day>a[month-1])
	{
		day=day-a[month-1];
		month++;
		if(month==13)
		{
			month=1;
			year++;
		}
		if((year%4==0&&year%100!=0)||year%400==0)
			a[1]=29;
		else a[1]=28;
	}
	printf("%d.%d.%d\n",year,month,day);
}
