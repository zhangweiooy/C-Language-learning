#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int q[12],sum,n;     //q��ʾ�� 
bool judge(int k)
{
	int i;
	for(i=0;i<k;i++)  //����k���ʺ�֮ǰ�Ļʺ� 
	{
		if(q[i]==q[k]||abs(k-i)==abs(q[k]-q[i]))
		    return false;
	}
	return true;
 } 
void nuclear(int k)    //kΪ��ǰ������ 
{
	int i;
	for(i=0;i<n;i++)   //��һ�е�λ�����μ��� 
	{
		q[k]=i;
		if(judge(k))
		{
			if(k==n-1)  //��N���ʺ� 
			    sum++;
			else
			    nuclear(k+1);//������һ���ʺ� 
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
