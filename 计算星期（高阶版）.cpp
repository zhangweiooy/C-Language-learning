#include <stdio.h>
int main()
{
    int y,m,d,w;
    scanf("%d%d%d",&y,&m,&d);
	if (m==1 || m==2)
    {
       m=(m==1?13:14);
       y=y-1;                                    //此处表示把1，2月计算到上一年的13，14月
    }
    w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;   //基姆拉尔森计算公式
    switch(w)
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
