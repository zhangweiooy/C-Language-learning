#include"stdio.h"
int main()
{
	int year,month,day,b=0,c,a;
	scanf("%d%d%d",&year,&month,&day);
	if(month>12||month<0)
	   {
	   printf("month is error.\n");
	   return 0;
	   }
	if(day<0)
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
	if((year%4==0&&year%100!=0)||year%400==0&&month==2)
	{
		if(day>29)
		{
		printf("day is error.\n");
			   return 0;	
		}
	}
	a=year-1;
	while(a>1900)
	{
	    if((a%4==0&&a%100!=0)||a%400==0)
	         b=b+1;
	    a=a-1; 
    }
    c=(year-1900)*365+b;  
	if((year%4==0&&year%100!=0)||year%400==0)
      {
      	switch(month)
      	 {
      	 	case 12:c=c+30;
      	 	case 11:c=c+31;
      	 	case 10:c=c+30;
      	 	case 9:c=c+31;
      	 	case 8:c=c+31;
      	 	case 7:c=c+30;
      	 	case 6:c=c+31;
      	 	case 5:c=c+30;
      	 	case 4:c=c+31;
      	 	case 3:c=c+29;
      	 	case 2:c=c+31;
      	 	case 1:;
		   }
	  }
	else 
	{
			switch(month)
      	 {
      	 	case 12:c=c+30;
      	 	case 11:c=c+31;
      	 	case 10:c=c+30;
      	 	case 9:c=c+31;
      	 	case 8:c=c+31;
      	 	case 7:c=c+30;
      	 	case 6:c=c+31;
      	 	case 5:c=c+30;
      	 	case 4:c=c+31;
      	 	case 3:c=c+28;
      	 	case 2:c=c+31;
      	 	case 1:;
		   }
	}             
    c=c+day-1;      
    switch(c%7)
    {
		case 0:printf("1\n");break;
		case 1:printf("2\n");break;
		case 2:printf("3\n");break;
		case 3:printf("4\n");break;
		case 4:printf("5\n");break;
		case 5:printf("6\n");break;
		case 6:printf("0\n");break;
	}
}  
