#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long t,i,n;
	char a[10]="123456789";
	cin>>t;
	while(t--)
	{
		cin>>n;
		i=ceil((sqrt(8*n+1)-1)/2)-1;
		n=n-i*(i+1)/2;
		if(n%9==0)
		    cout<<"9"<<endl;
		else
		    cout<<a[n%9-1]<<endl;
	}
	return 0;
}
