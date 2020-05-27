#include"stdio.h"
int day,ans=1;
int peach(int n)
{
	if(n==1)   return ans;
	ans=(ans+n-1)*2;
	peach(n-1);
 } 
int main()
{
	scanf("%d",&day);
	if(day==1)
	{
	   printf("The monkey got %d peach in first day.\n",ans);
	   return 0;
    }
	peach(day);
	printf("The monkey got %d peaches in first day.\n",ans);
}
