#include"stdio.h"
using namespace std;
long a[10005];
int main()
{
     int T;
     scanf("%d",&T);
     while (T--)
      {
      	int n;
        long max=-999999;
        long ans=0;
        int temp;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
		 {
		  scanf("%d",&temp);
		  if (temp>max)
		   max=temp;
		  if (temp>0)
		   ans+=temp;
	     }
	    if (ans==0)
	     printf("%ld\n",max);
	    else
	     printf("%ld\n",ans);
	  }
 } 

