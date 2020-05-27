#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
	int n,q[13]={0,1,0,0,2,10,4,40,92,352,724,2680};
	while(1)
	{
		cin>>n;
		if(n==0)
		    break;
		cout<<q[n]<<endl;
	}
	return 0;
}
