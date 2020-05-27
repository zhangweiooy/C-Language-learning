#include"stdio.h"
#include"math.h"
#include"string.h"
int main()
{
	char a[100],op;
	int max=-32768,min=32767,num=0,i,judge=1,j=0;
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		
		if(a[i]==',')
		{
		   num=j=0;
		   judge=1;
	    }
		if(a[i]>='0'&&a[i]<='9')
		{
			if(i>=1&&a[i-1]=='-')
			 	judge=0;
		    num=(a[i]-'0')+num*10;
		    if(judge==0&&a[i+1]==',')
		        num=-num;
		    if(a[i+1]==',')
		    {
			if(max<num)
		        max=num;
		    if(min>num)
		        min=num;
		    }
		}
		if(a[i]=='-'&&a[i+1]==',')
		    op='-';
		if(a[i]=='+'||a[i]=='*'||a[i]=='/'||a[i]=='%')
		    op=a[i];
		if(a[i]=='=')
		    break;
	}
	if((op=='/'||op=='%')&&min==0)
	    printf("Error!\n");
	else
	{
    	switch(op)
	    {
		case '+':
		    if(max<0&&min>=0)
		        printf("(%d) + %d = %d\n",max,min,max+min);
		    else if(max>=0&&min<0)
		             printf("%d + (%d) = %d\n",max,min,max+min);
		         else if(max<0&&min<0)
		                  printf("(%d) + (%d) = %d\n",max,min,max+min);
		              else
			               printf("%d + %d = %d\n",max,min,max+min);
						   break;
		case '-': if(max<0&&min>=0)
		        printf("(%d) - %d = %d\n",max,min,max-min);
		    else if(max>=0&&min<0)
		             printf("%d - (%d) = %d\n",max,min,max-min);
		         else if(max<0&&min<0)
		                  printf("(%d) - (%d) = %d\n",max,min,max-min);
		              else
			               printf("%d - %d = %d\n",max,min,max-min);
						   break;
		case '*':if(max<0&&min>=0)
		             printf("(%d) * %d = %d\n",max,min,max*min);
		         else if(max>=0&&min<0)
		             printf("%d * (%d) = %d\n",max,min,max*min);
		         else if(max<0&&min<0)
		                  printf("(%d) * (%d) = %d\n",max,min,max*min);
		              else
			               printf("%d * %d = %d\n",max,min,max*min);
						   break;
		case '/':if(max<0&&min>=0)
		        printf("(%d) / %d = %d\n",max,min,max/min);
		    else if(max>=0&&min<0)
		             printf("%d / (%d) = %d\n",max,min,max/min);
		         else if(max<0&&min<0)
		                  printf("(%d) / (%d) = %d\n",max,min,max/min);
		              else
			               printf("%d / %d = %d\n",max,min,max/min);
						   break;
		case '%':if(max<0&&min>=0)
		        printf("(%d) %% %d = %d\n",max,min,max%min);
		    else if(max>=0&&min<0)
		             printf("%d %% (%d) = %d\n",max,min,max%min);
		         else if(max<0&&min<0)
		                  printf("(%d) %% (%d) = %d\n",max,min,max%min);
		              else
			               printf("%d %% %d = %d\n",max,min,max%min);
						   break;             //注意此处应有两个%号 
	    } 
	    
    }
    return 0;
 } 
