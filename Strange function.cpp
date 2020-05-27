#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double y;
double fun(double x)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*x*x-y*x;
}
double tsearch(double left,double right)
{
	double mid,rmid;
	while(left<right-1e-6)
	{
		mid=(left+right)/2;
	    rmid=(mid+right)/2;
		if(fun(mid)>fun(rmid))
	        left=mid;
	    else
	        right=rmid;
	}
	return mid;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>y;
		printf("%.4lf\n",fun(tsearch(0.0,100.0)));
	}
}
