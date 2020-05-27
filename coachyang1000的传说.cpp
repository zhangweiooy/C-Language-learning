#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
char name[1002][20],temp[20];
priority_queue<int> q[1002];
int main()
{
	int n,i,j,tmp,judge;
	while(scanf("%d\n",&n)!=EOF)
	{
		memset(name,0,sizeof(name));
		int k=0,kk=0;
		for(i=0;i<n;i++)
		{
			judge=0;
			scanf("%s%d",temp,&tmp);
			for(j=0;j<k;j++)
			    if(strcmp(temp,name[j])==0)
			    {
			    	q[j].push(tmp);
			    	judge=1;
				}
			if(judge==1)    continue;
			strcpy(name[k++],temp);
			q[k-1].push(tmp);
		}
		int ans=0,count;
		for(i=0;i<k;i++)
		{
			count=0;
			while(!q[i].empty()&&count<5)
			{
				ans+=q[i].top();
				count++;
				q[i].pop();
			}
			while(!q[i].empty())
			    q[i].pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
