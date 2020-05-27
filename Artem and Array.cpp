#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long ans=0;
int main()
{
	long long n,i=-1,j,temp=0;
	scanf("%lld",&n);
	long long a[n];
	while(n--)
	{
		scanf("%lld",&temp);
		while(i>=1&&(temp>=a[i]&&a[i]<=a[i-1]))
		{
			ans+=min(a[i-1],temp);
			i--;
		}
		i++;
		a[i]=temp;
	}
	sort(a,a+i+1);
	for(j=0;j<=i-2;j++)
	    ans+=a[j];
	printf("%lld\n",ans);
	return 0;
}

