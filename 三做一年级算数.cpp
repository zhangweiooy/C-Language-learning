#include"stdio.h"
int main()
{
	char a[80]={0},max='0',min='9';
	int i=0;
	scanf("%s",a);
	while(a[i]!='=')
	{
		if(a[i]>='0'&&a[i]<='9')
		{
		if(max<a[i])
		    max=a[i];
		if(min>a[i])
		    min=a[i];
		}
		i+=2;
	}
	if(a[i-2]=='/'&&min=='0')
    {
    	printf("Error!\n");
    	return 0;
	}
	max=max-48;
	min=min-48;
	switch(a[i-2])
	{
		case '+':printf("%d+%d=%d\n",max,min,max+min);break;
		case '-':printf("%d-%d=%d\n",max,min,max-min);break;
		case '*':printf("%d*%d=%d\n",max,min,max*min);break;
		case '/':printf("%d/%d=%d\n",max,min,max/min);break;
		case '%':printf("%d%%%d=%d\n",max,min,max%min);break;              //注意此处应有两个%号 
	} 
}
