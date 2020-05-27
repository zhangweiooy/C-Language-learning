#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,tree[100005],a[100005];
int lowbit(int x)
{
	return x&(-x);
}
void update(int i,int a)
{
	if(i==0)  return ;
	while(i<=n)
	{
		tree[i]=tree[i]^a;
		i+=lowbit(i);
	}
}
int getsum(int x)
{
	int s=0;
	while(x>0)
	{
		s^=tree[x];
		x-=lowbit(x);
	}
	return s;
}
int main()
{
	int i,j,op,l,r;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			update(i,a[i]);
		}
		while(m--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d",&l,&r);
				printf("%d\n",getsum(r)^getsum(l-1));
			}
			else  if(op==2)
			      {
			      	scanf("%d%d",&l,&r);
			      	r=(getsum(l)^getsum(l-1))^r;
			      	update(l,r);
				  }
				  else  if(op==3)
				        {
				        	int k;
				        	for(k=1;k<n;k++)
			                    update(k,a[k+1]);
			                update(n,a[1]);
						}
		}
	}
	return 0;
}
