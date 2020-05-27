#include<stdio.h> 
int main()
{
    int i,n;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
	    int a;
		scanf("%d",&a); 
		if(a>1)
		    if(a%2==0)
		        printf("%d\n",a-1);
		    else
		        printf("%d\n",a);
		else 
		    printf("0\n");
	}
}
