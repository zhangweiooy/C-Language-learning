#include"stdio.h"
#include"stdlib.h"
long ans=0,max;
long l,n,m;
long d[500005];
int i,j; 
int judge(long mid)
{
	long count=0,last=0;
	if(d[0]>mid)
	    return 0;
	for(i=1;i<n;i++)                       // 判断现步与上一步之间的间隔大于这个中间值的次数是不是超过步数
	{
		if(d[i]-last>mid)                  //这么多次都需要跳的比这个mid值远，则该值不为最小 
		{
			count++;
			last=d[i-1];
		}
	}
	if(count>=m)
	    return 0;
	return 1;
}
void binsearch(long left,long right)
{
	if(left<=right)
	{
		long mid=(right+left)/2;
		if(judge(mid))
		{
	     	ans=mid;
            binsearch(left,mid-1);	        
	    }
	    else
	        binsearch(mid+1,right);
	}
	else
	    return ;
}
int cmp(const void *a,const void *b)
{
	return *(long *)a-*(long *)b;
}
int main()
{
	scanf("%ld %ld %ld",&l,&n,&m);
	for(i=0;i<n;i++)
	    scanf("%ld",&d[i]);
	d[n]=l;                       //注意不要忘记了最后一步 
	n+=1;
	qsort(d,n,sizeof(d[0]),cmp);
	max=d[0];
	for(i=1;i<n;i++)
	{
		if(d[i]-d[i-1]>max)
		    max=d[i]-d[i-1];
	}
	binsearch(max,l);
	printf("%ld\n",ans);
	return 0;
}
