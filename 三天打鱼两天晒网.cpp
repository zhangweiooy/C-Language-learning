#include"stdio.h"
int main()
{
	int t,i,a,y,d,m;
	scanf("%d",&t);
	while(t--)
	{
		a=0;
		scanf("%d%d%d",&y,&m,&d);
		for(i=1990;i<=y-1;i++)
		{
			if((i%4==0&&i%100!=0)||i%400==0)
			    a=a+1;
		}
		a=a+365*(y-1990);
		switch(m)
		{
			case 12:a=a+30;
			case 11:a=a+31; 
			case 10:a=a+30;
      	 	case 9:a=a+31;
      	 	case 8:a=a+31;
      	 	case 7:a=a+30;
      	 	case 6:a=a+31;
      	 	case 5:a=a+30;
      	 	case 4:a=a+31;
      	 	case 3:a+=((y%4==0&&y%100!=0)||y%400==0)?29:28;
      	 	case 2:a=a+31;
      	 	case 1:;
		}
		a=a+d;
		if(a%5==4||a%5==0)
		    printf("He was basking on %d.%d.%d\n",y,m,d);
		else
		    printf("He was fishing on %d.%d.%d\n",y,m,d);
	}
	return 0;
}
