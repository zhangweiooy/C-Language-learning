#include"stdio.h"
int f(int a,int b) 
{
    int c=1,i; 
	for(i=1;i<=a;i++) 
	{
	    c*=(b-i+1);
	    c=c/i;
	}                             //������ϣ�C*�����Ӷ�������ѡ����˳������ 
	return(c);
} 
int main()
{
	int a[2]={1,5},n;
	while(scanf("%d",&n)!=EOF)
	{
		int temp,i,j,count=0;
		for(i=0;i<=n;i++)
		{
			temp=i*1+(n-i)*5;
			if(temp%3==0)
			    count+=f(i,n);
		}
		printf("%d\n",count);
	}
	return 0;
}
