#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int q[12],sum,n;     //q表示列 
bool judge(int k)
{
	int i;
	for(i=0;i<k;i++)  //检查第k个皇后之前的皇后 
	{
		if(q[i]==q[k]||abs(k-i)==abs(q[k]-q[i]))
		    return false;
	}
	return true;
 } 
void nuclear(int k)    //k为当前横坐标 
{
	int i;
	for(i=0;i<n;i++)   //在一行的位置依次检索 
	{
		q[k]=i;
		if(judge(k))
		{
			if(k==n-1)  //第N个皇后 
			    sum++;
			else
			    nuclear(k+1);//继续下一个皇后 
		}
	}
	return ;
}
int main()
{
	while(1)
	{
		cin>>n;
		if(n==0)
		    break;
		sum=0;
		memset(q,0,sizeof(q));
		nuclear(0);
		cout<<sum<<endl;
	}
	return 0;
 } 
