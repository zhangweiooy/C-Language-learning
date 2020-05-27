#include"stdio.h"
int fun1(int a,int b)
{
	int c;
	c=a%b;
	if(c==0)
	    return b;
	else
	    fun1(b,c);
}
int fun2(int a,int b,int ans1)
{
	return a*b/ans1;
}
int main()
{
	int a,b,c,ans1,ans2,temp;
	scanf("%d,%d",&a,&b);
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	ans1=fun1(a,b);
	ans2=fun2(a,b,ans1);
	printf("最大公约数：%d\n最小公倍数：%d\n",ans1,ans2);
	return 0;
 } 
