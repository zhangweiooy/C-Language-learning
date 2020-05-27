#include <stdio.h>  
  
// ��������ԭ��  
int leap_year( int );     
int year_days( int );     
int days(int,int,int);    
  
int leap_year( int year )   // �ж������ƽ��  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}  
  
int year_days(int year)     // ����һ���������  
{   return leap_year( year ) ? 366 : 365;  
}  
 
int days( int year, int month, int day ) // �������month,day �Ǳ���year�ĵڼ���  
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}  
int main()
{
	int y1,y2,m1,m2,d1,d2,days1,days2,ans,i=0;    //i��ʾ������� ������ 
	scanf("%d%d%d",&y1,&m1,&d1);
	scanf("%d%d%d",&y2,&m2,&d2);
	days1=days(y1,m1,d1);
	days2=days(y2,m2,d2);
	for(;y1<y2;y1++)
	    i+=year_days(y1);
	ans=days2+i-days1;
	if(ans==1)
	    printf("1 day\n");
	else
	    printf("%d days\n",ans);
	return 0;
}

