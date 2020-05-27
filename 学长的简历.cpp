#include"stdio.h"
int count;
void sub(int i,int n,int first,int b[])
{
	int j;
	for(j=i+1;j<n;j++)
	{
		if(b[j]>=first)
		{
			count++;
			sub(j,n,b[j],b);
		}
	}
	return ;
}

int main()
{
	int n;
	count = 0;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	    sub(i,n,a[i],a); 
    printf("%d\n",count+n);
}
