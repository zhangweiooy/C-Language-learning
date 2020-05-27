#include<map>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	map<int,vector<int> > a;
	int n,m,i,t,k,v;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		a.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			a[t].push_back(i);
		}
		while(m--)
		{
			scanf("%d %d",&k,&v);
			if(k>a[v].size()||a.count(v)<1)
			    printf("0\n");
			else
			    printf("%d\n",a[v][k-1]);
		}
	}
	return 0;
 } 
