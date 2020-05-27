#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a,tree[50005];
char op[8];
int lowbit(int x)
{
	return x&(-x);
}
void update(int i,int a)
{
	if(i==0)  return ;
	while(i<=n)
	{
		tree[i]+=a;
		i+=lowbit(i);
	}
}
int getsum(int x)
{
	int s=0;
	while(x>0)
	{
		s+=tree[x];
		x-=lowbit(x);
	}
	return s;
}
int main()
{
	int t,i,j,Case=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		Case++;
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++)
		{
			 cin>>a;
			 update(i,a);
		}
		printf("Case %d:\n",Case);
		while(1)
		{
			scanf("%s",op);
			if(op[0]=='E')
			    break;
			cin>>i>>j;
			if(op[0]=='A')
			    update(i,j);
			else  if(op[0]=='S')
			          update(i,-j);
			      else  if(op[0]=='Q')
			                cout<<getsum(j)-getsum(i-1)<<endl;
		}
	}
	return 0;
}
