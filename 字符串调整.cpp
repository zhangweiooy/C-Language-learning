#include"stdio.h"
#include"string.h"
int judge(char p)
{
	if(p>='a'&&p<='z'||p>='A'&&p<='Z')
	    return 1;
	else
	    return 0;
}
int compare(char p,char q)
{
	if(p>q)
	    return 1;
	else return 0;
}
int main()
{
	char a[10000],temp;
	int left,right;
	gets(a);
	left=0;
	right=strlen(a)-1;
	while(left<right)
	{
		while(judge(a[left])==0)
		    left++;
		while(judge(a[right])==0)
		    right--;
		if(compare(a[left],a[right])==1)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
		left++;
		right--;
	}
	puts(a);
	return 0;
}
