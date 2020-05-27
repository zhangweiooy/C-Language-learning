#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,max=0,i,j;
	vector<int> a;
	scanf("%d",&n);
	while(n)
	{
		a.push_back(n%10);
		if(n%10>max)
		    max=n%10;
		n/=10;
	}
	reverse(a.begin(),a.end());
	printf("%d\n",max);
	for(i=0;i<max;i++)
	{
		int flag=0;
		for(j=0;j<a.size();j++)
		{
			if(a[j]>0)
			    {flag=1;a[j]--;printf("1");}
			else{ 
			    if(flag==1)
			        printf("0");
			}
		}
		printf(" ");
	}
	return 0;
}
