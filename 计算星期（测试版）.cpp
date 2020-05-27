#include"stdio.h"
main()
{
	int year,month,day,week;
	scanf("%d%d%d",&year,&month,&day);
	if(month>12||month<=0)
	   {
	   printf("month is error.\n");
	   return 0;
	   }
	if(day<=0)
	{
		printf("day is error.\n");
			   return 0;
	}
	if(year%100==0&&year%400!=0&&month==2&&day>28)
		{
	printf("day is error.\n");
	return 0;
	}  
	if(year%4!=0&&month==2&&day>28)
	{
	printf("day is error.\n");
	return 0;
	}   
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	    {
	    	if(day>31)
	    	   {
			   printf("day is error.\n");
			   return 0;
			   }
		 } 
	if(month==4||month==6||month==9||month==11)
	{
		if(day>30)
		{
			printf("day is error.\n");
			   return 0;
		}
	}
	if((year%4==0&&year%100!=0)||(year%400==0&&month==2))
	{
		if(day>29)
		{
		printf("day is error.\n");
			   return 0;	
		}
	}
	
	if (month==1 || month==2)
    {
       month=(month==1?13:14);
       year=year-1;                                    //此处表示把1，2月计算到上一年的13，14月
    }
    week=(day+2*month+3*(month+1)/5+year+year/4-year/100+year/400+1)%7;   //基姆拉尔森计算公式
    switch(week)
    {
		case 0:printf("0\n");break;
		case 1:printf("1\n");break;
		case 2:printf("2\n");break;
		case 3:printf("3\n");break;
		case 4:printf("4\n");break;
		case 5:printf("5\n");break;
		case 6:printf("6\n");break;
	}
}  
