#include"stdio.h"
#include"string.h"
int main()
{
	char a[100],assist;
	long n,i,j,max;
	scanf("%ld",&n);
	sprintf(a,"%ld",n);
	for(i=0;i<strlen(a)-1;i++)
	{
		max=i;
		for(j=i+1;j<strlen(a);j++)
		    if(a[max]<a[j])
		        max=j;
		assist=a[max];
		a[max]=a[i];
		a[i]=assist;                   //½»»» 
	}
	printf("%s\n",a);
}
