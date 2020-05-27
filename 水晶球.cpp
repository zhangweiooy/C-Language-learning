#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
int id0,id1,id2;
struct node
{
	int a;int b;int c;int id;     //abcÉýÐòÅÅÁÐ 
 }cub[100000];
 struct ffff
 {
 	int a;int b;int c;int iid1;int iid2;
 }temp[100000];
 int min(int x,int y)
 {
 	if(x>y)
 	    return y;
 	else
 	    return x;
 }
 int mid(int x,int y,int z)
 {
 	if((z<=x&&x<=y)||(z>=x&&x>=y))
 	    return x;
 	if((x<=z&&z<=y)||(x>=z&&z>=y))
 	    return z;
 	if((z<=y&&y<=x)||(z>=y&&y>=x))
 	    return y;
 }
 int max(int x,int y)
 {
 	if(x>y)
 	    return x;
 	else
 	    return y;
 }
 void lay(int i,int t1,int t2,int t3)
 {
	cub[i].a=min(min(t1,t2),t3);
	cub[i].b=mid(t1,t2,t3);
	cub[i].c=max(max(t1,t2),t3);
	cub[i].id=i+1;
	return ;
 }
 bool cmp(node x,node y)
 {
 	if(x.c!=y.c)
 	    return x.c>y.c;
 	else
 	    if(x.b!=y.b)
 	        return x.b>y.b;
 	    else
 	        return x.a>y.a;
 }
int main()
{
	int n,i,j,t1,t2,t3,max1=0,max2=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t1>>t2>>t3;
		lay(i,t1,t2,t3);
		if(max1<cub[i].a)
		{    
		    max1=cub[i].a;
		    id0=cub[i].id;
		}
	}
	sort(cub,cub+n,cmp);
	for(i=1,j=0;i<n;i++)
	{
		if(cub[i-1].c==cub[i].c&&cub[i].b==cub[i].b&&(cub[i-1].a+cub[i].a)>max2)
		{
			max2=cub[i].a+cub[i-1].a;
			id1=cub[i-1].id;
			id2=cub[i].id;
			temp[j].a=min(min(cub[i].c,cub[i].b),max2);
			temp[j].b=mid(cub[i].c,cub[i].b,max2);
			temp[j].c=max(max(cub[i].c,cub[i].b),max2);
			temp[j].iid1=id1;
			temp[j].iid2=id2;
			j++;
		 } 
	}
	max2=0;
	for(i=0;i<j;i++)
	{
		if(temp[i].a>max2)
		{
			max2=temp[i].a;
			id1=temp[i].iid1;
			id2=temp[i].iid2;
		}
	}
	if(max1>=max2)
	{
		cout<<"1"<<endl;
		cout<<id0<<endl;
	}
	else
	{
		cout<<"2"<<endl;
		cout<<min(id1,id2)<<" "<<max(id1,id2)<<endl;
	}
 } 
