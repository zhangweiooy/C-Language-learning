#include"stdio.h"

int main()
{
	int n,i,j;
	char ch;
	scanf("%d,%c",&n,&ch);
	if(n==1){
		printf("%c\n",ch);
		return 0;
	}
	for(j=1;j<=n-1;j++)
	    printf(" ");
	printf("%c\n",ch);
	                               //µÚÒ»ÐÐ 
	for(i=2;i<n;i++){
		for(j=1;j<=n-i;j++)
		    printf(" ");
		printf("%c",(ch+2*i-3-'a')%26+'a');
		for(j=1;j<=2*i-3;j++)
			printf(" ");
		printf("%c\n",(ch+2*i-3+1-'a')%26+'a');
		
	}
	
	for(j=1;j<=2*n-1;j++)
	    printf("%c",(ch+2*i-3+j-1-'a')%26+'a');
	printf("\n");
	return 0;
}
