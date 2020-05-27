#include<cstdio>
#include<queue>
#include<cstdlib>
#include<iostream> 
using namespace std;
int main()
{
	int n,i,ta,tb;
	char temp;
	queue<int> a;//D
	queue<int> b;//X
	while(!a.empty())
	    a.pop();
	while(!b.empty())
	    b.pop();
	i=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		if(temp=='D')
		    a.push(i+1);
		if(temp=='X')
		    b.push(i+1);
	}
	if(a.empty())
	{
		cout<<"X"<<endl;
		return 0;
	}
	if(b.empty())
	{
		cout<<"D"<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		ta=a.front();
		tb=b.front();
		if(ta<tb)
		{
			b.pop();
			a.push(ta+n);
			a.pop();
		}
		else
		{
			a.pop();
			b.push(tb+n);
			b.pop();
		}
		if(a.empty())
		{
			cout<<"X"<<endl;
			break;
		}
		if(b.empty())
		{
			cout<<"D"<<endl;
			break;
		}
	 } 
	return 0;
}
