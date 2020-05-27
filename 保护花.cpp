#include<cstdio>
#include<algorithm>
#include<cstdlib> 
using namespace std;
typedef struct m
{
	int t;
	int d;
}COW;
COW cow[100002];
bool compare(COW a,COW b)
{
	return a.t*1.0/a.d<b.t*1.0/b.d;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&cow[i].t,&cow[i].d);
	}
	sort(cow,cow+n,compare);
	long long temp=0,ans=0;
	for(j=0;j<n;j++)
		temp+=cow[j].d;
	for(i=0;i<n;i++)
	{
		temp-=cow[i].d;
		ans+=temp*cow[i].t*2;
	}
	printf("%lld\n",ans);
	return 0;
}
