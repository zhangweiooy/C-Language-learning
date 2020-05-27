#include"stdio.h"
int main()
{
	int max=0,begin=-1,begin0,end0,judge1=0,judge2=0,end,s=1,i,n;
	scanf("%d",&n);
	int a[n];
	for(i= 0;i<n;i++)
	    scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			if(judge1==0)  begin=i-1;
			end=i;
			judge1=1;
			s++;
		}
		if(s>max)
		{
		    begin0=begin;
		    end0=end;
		    max=s;
		}
		if(a[i]!=a[i-1])
		{ 
			judge1=0;
			s=1;
		}
	}
	if(begin==-1)
	    printf("No equal number list.\n");
	else
	    printf("The longest equal number list is from %d to %d.\n",begin0,end0);
	return 0; 
}
