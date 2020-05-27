#include<cstdio>
#include<cstring>
#include<iostream>
#include <algorithm>
#include<cstdlib>
using namespace std;
int i,j,flag1=0,flag2=0,k=0,len,sum,repeat[7000000];
int main()
{
	char a[20],b[20];
	memset(repeat,0,sizeof(repeat));
	cout<<"Error:"<<endl;
	while(scanf("%s",a)!=EOF)
	{		
		memset(b,0,sizeof(b));
	    len=strlen(a);
	    for(i=0,j=0;i<len;i++)
	    {
	    	if(a[i]=='-')
	    	    continue;
	    	else
	    	    {
	    	    	b[j]=a[i];
	    	    	j++;
				}
		}
		len=strlen(b);
		sum=0;
		for(i=0;i<len;i++)
		{
			if(i==0)
			    if(b[i]!='3'&&b[i]!='6'&&b[i]!='D'&&b[i]!='E'&&b[i]!='F'&&b[i]!='M'&&b[i]!='N'&&b[i]!='O')
			    {
			    	flag1=1;
			    	cout<<a<<endl;
			    	goto k;
				}
			if(b[i]=='Q'||b[i]=='Z')
			{
				flag1=1;
				cout<<a<<endl;
				goto k;
			}
			else if(b[i]=='A'||b[i]=='B'||b[i]=='C')
			         b[i]='2';
			else if(b[i]=='D'||b[i]=='E'||b[i]=='F')
			         b[i]='3';
			else if(b[i]=='G'||b[i]=='H'||b[i]=='I')
			         b[i]='4';
			else if(b[i]=='J'||b[i]=='K'||b[i]=='L')
			         b[i]='5';
			else if(b[i]=='M'||b[i]=='N'||b[i]=='O')
			         b[i]='6';
			else if(b[i]=='P'||b[i]=='R'||b[i]=='S')
			         b[i]='7';
			else if(b[i]=='T'||b[i]=='U'||b[i]=='V')
			         b[i]='8';
			else if(b[i]=='W'||b[i]=='X'||b[i]=='Y')
			         b[i]='9';
		}
		sum=atoi(b);             //转化为整形 
		repeat[sum]++;
		k:;
	}
	if(flag1==0)
	    cout<<"Not found."<<endl;
	sort(repeat,repeat+k);
	cout<<endl<<"Duplication:"<<endl;
	for(i=0;i<7000000;i++)
	{
		if(repeat[i]>1)
		{
			flag2=1;
			printf("%d-%04d %d\n",i/10000,i%10000,repeat[i]);
		}
	}
	if(flag2==0)
	    cout<<"Not found."<<endl;
	
}
