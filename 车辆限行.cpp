#include <stdio.h>  
  
// 声明函数原型  
int leap_year( int );     
int year_days( int );     
int days(int,int,int);    
  
int leap_year( int year )   // 判断闰年或平年  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}  
  
int year_days(int year)     // 计算一整年的天数  
{   return leap_year( year ) ? 366 : 365;  
}  
 
int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天  
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}  
int main()
{
	int y0,y,m,d,days1,days2,ans,i=0;    //i表示相隔整年 的天数 
	float week;
	scanf("%d%d%d",&y,&m,&d);
	days1=days(2012,4,8);
	days2=days(y,m,d);
	for(y0=2012;y0<y;y0++)
	    i+=year_days(y0);
	ans=days2+i-days1;
    week=ans*1.0/7/13;
    while(week>5)
        week-=5;
    if(week>0&&week<=1)
    {
    	switch(ans%7)
    	{
    		case 0:printf("Free.\n"); break;
    		case 6:printf("Free.\n"); break;
    		case 1:printf("3 and 8.\n");break;
    		case 2:printf("4 and 9.\n");break;
    		case 3:printf("5 and 0.\n");break;
    		case 4:printf("1 and 6.\n");break;
    		case 5:printf("2 and 7.\n");break;
		}
	}
	if(week>1&&week<=2)
	{
		switch(ans%7)
		{
			case 0:printf("Free.\n"); break;
    		case 6:printf("Free.\n"); break;
    		case 1:printf("2 and 7.\n");break;
    		case 2:printf("3 and 8.\n");break;
    		case 3:printf("4 and 9.\n");break;
    		case 4:printf("5 and 0.\n");break;
    		case 5:printf("1 and 6.\n");break;
		}
	}
	if(week>2&&week<=3)
	{
		switch(ans%7)
		{
			case 0:printf("Free.\n"); break;
    		case 6:printf("Free.\n"); break;
    		case 1:printf("1 and 6.\n");break;
    		case 2:printf("2 and 7.\n");break;
    		case 3:printf("3 and 8.\n");break;
    		case 4:printf("4 and 9.\n");break;
    		case 5:printf("5 and 0.\n");break;
		}
	}
	if(week>3&&week<=4)
	{
		switch(ans%7)
		{
			case 0:printf("Free.\n"); break;
    		case 6:printf("Free.\n"); break;
    		case 1:printf("5 and 0.\n");break;
    		case 2:printf("1 and 6.\n");break;
    		case 3:printf("2 and 7.\n");break;
    		case 4:printf("3 and 8.\n");break;
    		case 5:printf("4 and 9.\n");break;
		}
	}
	if(week>4&&week<=5)
	{
		switch(ans%7)
		{
			case 0:printf("Free.\n"); break;
    		case 6:printf("Free.\n"); break;
    		case 1:printf("4 and 9.\n");break;
    		case 2:printf("5 and 0.\n");break;
    		case 3:printf("1 and 6.\n");break;
    		case 4:printf("2 and 7.\n");break;
    		case 5:printf("3 and 8.\n");break;
		}
	}
	return 0;
}

