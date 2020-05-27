#include"stdio.h"
#include"string.h"
int main()
{
	char a[2000],j;
	long year,month,day,length,i,t,judge=0,check;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",a);
		length=strlen(a);
		if(length!=15 &&length!= 18)
		{
			printf("Invalid\n");
		}
		if(length==18)
		{
		year=(a[6]-'0')*1000+(a[7]-'0')*100+(a[8]-'0')*10+(a[9]-'0');
		month=(a[10]-'0')*10+(a[11]-'0');
		day=(a[12]-'0')*10+(a[13]-'0');
		if(year<1||month<1||month>12||day<1)
		    judge=1;
		if(((year%4==0&&year%100!=0)||year%400==0)&&month==2&&day>29)      //闰年二月 
	        judge=1;
		if((year%4!=0||(year%100==0&&year%400!=0))&&month==2&&day>28)              //平年 二月 
		    judge=1;
		if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)  //大月 
			judge=1;
		if((month==4||month==6||month==9||month==11)&&day>30)	                              //小月 
		    judge=1;
		check=((a[0]-'0')*7+9*(a[1]-'0')+10*(a[2]-'0')+5*(a[3]-'0')+8*(a[4]-'0')+4*(a[5]-'0')+2*(a[6]-'0')+1*(a[7]-'0')+6*(a[8]-'0')+3*(a[9]-'0')+7*(a[10]-'0')+9*(a[11]-'0')+10*(a[12]-'0')+5*(a[13]-'0')+8*(a[14]-'0')+4*(a[15]-'0')+2*(a[16]-'0'))%11;
		switch(check)
		{
			case 0:j='1';break;
			case 1:j='0';break;
			case 2:j='X';break;
			case 3:j='9';break;
			case 4:j='8';break;
			case 5:j='7';break;
			case 6:j='6';break;
			case 7:j='5';break;
			case 8:j='4';break;
			case 9:j='3';break;
			case 10:j='2';break;
	    }
	    if(j!=a[17])
	        judge=1;
	    if(judge==0)
	        printf("Valid\n");
	    else    printf("Invalid\n");
	    judge=0;
	    }
	    if(length==15)
	    {
	    	if((a[length-1]=='6'||a[length-1]=='7'||a[length-1]=='8'||a[length-1]=='9')&&a[length-2]=='9'&&a[length-3]=='9')
	        {
	        	for(i=length-1;i>5;i--)
	        	    a[i+2]=a[i];
	        	a[6]='1';
	        	a[7]='8';
			}
			else
			{
				for(i=length-1;i>5;i--)
	        	    a[i+2]=a[i];
	        	a[6]='1';
	        	a[7]='9';
			}
			check=((a[0]-'0')*7+9*(a[1]-'0')+10*(a[2]-'0')+5*(a[3]-'0')+8*(a[4]-'0')+4*(a[5]-'0')+2*(a[6]-'0')+1*(a[7]-'0')+6*(a[8]-'0')+3*(a[9]-'0')+7*(a[10]-'0')+9*(a[11]-'0')+10*(a[12]-'0')+5*(a[13]-'0')+8*(a[14]-'0')+4*(a[15]-'0')+2*(a[16]-'0'))%11;
	    	switch(check)
	    	{
			    case 0:j='1';break;
		    	case 1:j='0';break;
		    	case 2:j='X';break;
		    	case 3:j='9';break;
		    	case 4:j='8';break;
		    	case 5:j='7';break;
		    	case 6:j='6';break;
		    	case 7:j='5';break;
		    	case 8:j='4';break;
		    	case 9:j='3';break;
		    	case 10:j='2';break;
	    	}
	    	a[17]=j;
	    	a[18]='\0';
	    	puts(a);
        }
    }
    return 0;
}
