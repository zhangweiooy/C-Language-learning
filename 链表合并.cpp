#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int cmp(const void *a,const void *b)
{
	return *(char *)a-*(char *)b ;
}
int main()
{
	char garbage='a',a[1000]={'\0'},b[1000]={'\0'};
	int i,j=0,k=0,judge=0,flag=0;
	for(i=0;garbage!='\n';i++)
	    scanf("%c%c",&a[i],&garbage);
	garbage='a';
	for(i=0;garbage!='\n';i++)
	    scanf("%c%c",&b[i],&garbage);
	
	strcat(a,b);
    qsort(a,strlen(a),sizeof(a[0]),cmp);
    for(i=0;i<strlen(a);i++)
    {
    	if(i==0)
    	    continue ;
    	if(a[i]==a[i-1])
    	    a[i-1]='0';
	}
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='0')
		    continue ;
		if(flag==0)
		{
			printf("%c",a[i]);
			flag=1;
		}
		else
		    printf(" %c",a[i]);
	}
	printf("\n");
	return 0;
}
