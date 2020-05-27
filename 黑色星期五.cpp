#include"stdio.h"
int main()
{
	int year,month[13]={0},day[12],b=0,m[12]={0},i,k=0,count=0,c,a;
	scanf("%d",&year);
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
      	month[1]=13;
      	month[2]=31+13;
      	month[3]=31+29+13;
      	month[4]=31+29+31+13;
      	month[5]=31+29+31+30+13;
      	month[6]=31+29+31+30+31+13;
      	month[7]=31+29+31+30+31+30+13;
      	month[8]=31+29+31+30+31+30+31+13;
      	month[9]=31+29+31+30+31+30+31+31+13;
      	month[10]=31+29+31+30+31+30+31+31+30+13;
      	month[11]=31+29+31+30+31+30+31+31+30+31+13;
      	month[12]=31+29+31+30+31+30+31+31+30+31+30+13;
	  }
	else 
	{
		month[1]=13;
      	month[2]=31+13;
      	month[3]=31+28+13;
      	month[4]=31+28+31+13;
      	month[5]=31+28+31+30+13;
      	month[6]=31+28+31+30+31+13;
      	month[7]=31+28+31+30+31+30+13;
      	month[8]=31+28+31+30+31+30+31+13;
      	month[9]=31+28+31+30+31+30+31+31+13;
      	month[10]=31+28+31+30+31+30+31+31+30+13;
      	month[11]=31+28+31+30+31+30+31+31+30+31+13;
      	month[12]=31+28+31+30+31+30+31+31+30+31+30+13;
	}             
    for(i=0;i<12;i++)
	{
		day[i]=c+month[i+1]-1;
	    if(day[i]%7==4)
	    {
	    	count++;
	        m[k]=i+1;
			k++;    
		}
	}     
    if(count==1)
    {
	    printf("There is 1 Black Friday in year %d.\n",year);
	    printf("It is:\n");
	}
	else
	{
	    printf("There are %d Black Fridays in year %d.\n",count,year);
	    printf("They are:\n");
	}
	
	for(i=0;i<k;i++)
	    printf("%d/%d/13\n",year,m[i]);
	return 0;
}  
