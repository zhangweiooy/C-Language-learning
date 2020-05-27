#include<cstdio>
#include<cstring>
using namespace std;
int fun(int k)
{
	k=k%4;
	if(k==1)
	    return 5;
	if(k==2)
	    return 3;
	if(k==3)
	    return 1;
	if(k==0)
	    return 0;
}
int main()
{
	int a[7],judge=0,i;
	while(1)
	{
		judge=0; 
		for(i=1;i<=6;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]!=0)
			    judge=1;
		}
		if(judge==0)
		    break;
		int ans=a[6]+a[5]+a[4]+(a[3]+3)/4;
		int a2=a[4]*5+fun(a[3]);            //留给2*2箱子的空间 
		if(a[2]>a2)
		    ans+=(a[2]-a2+8)/9;
		int a1=ans*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;//留给1*1箱子的空间 
		if(a[1]>a1)
		    ans+=(a[1]-a1+35)/36;
		printf("%d\n",ans);
	}
	return 0;
}
