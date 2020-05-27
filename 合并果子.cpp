#include"stdio.h"
int n,a[10010]={0};
void sort(int m)
{
	int j,q,temp;
	q=m;
	for(j=q+1;j<n;j++)
	    if(a[j]<a[q])
	        q=j;
	if(q!=m)
	{
		temp=a[q];
		a[q]=a[m];
		a[m]=temp;
	}
	return ;
}
int main()
{
	long long ans=0;
	int i;
	scanf("%d",&n);
	
        for(i=0;i<n;i++)
		    scanf("%d",&a[i]);
		sort(0);
		sort(1);
		for(i=1;i<n;i++)
		{
			a[i]+=a[i-1];
			ans+=a[i];
			sort(i);
			sort(i+1); 
		}
		printf("%lld\n",ans);
	
	return 0;
}
