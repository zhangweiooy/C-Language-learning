# include<stdio.h>
# include<stdlib.h>
#include <stdbool.h>
long long a[1000010];
bool judge1(long long x)
{
	if(x>1&&a[x]<a[x/2])
	    return true;
	else
	    return false;
}
bool judge2(long long x,int len)
{
	if((x*2<=len&&a[x]>a[x*2])||(x*2+1<=len&&a[x]>a[x*2+1]))
	    return true;
	else
	    return false;
}
int main(){
    long long sum=0,ans=0,h,r,j;
    int n,i,t;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            r=i;
            while(judge1(r)){ 
                h=a[r];
                a[r]=a[r/2];
                a[r/2]=h;
                r/=2;
        }
    }
    int len=n;
    for(i=1;i<n;i++)
	{
        sum=a[1];
        a[1]=a[len];
        len--;
        r=1;
        while(judge2(r,len))
		{
            j=r*2;
            if(j+1<=len&&a[j]>a[j+1])j++;
            h=a[r];
            a[r]=a[j];
            a[j]=h;
            r=j;
        }
        sum+=a[1];
        a[1]=a[len];
        len--;
        r=1;
        while(judge2(r,len))
		{
            j=r*2;
            if(j+1<=len&&a[j]>a[j+1])
			j++;
            h=a[r];
            a[r]=a[j];
            a[j]=h;
            r=j;
        }
        ans+=sum;
        a[++len]=sum;
        r=len;
        while(judge1(r))
		{
            h=a[r];
            a[r]=a[r/2];
            a[r/2]=h;
            r/=2;
        }
    }
    printf("%lld\n",ans);
    }
}
