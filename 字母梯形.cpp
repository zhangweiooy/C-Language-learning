#include"stdio.h"
int main()
{
	int n,i,j;
	char ch,s;
	scanf("%d %c",&n,&s);
	if(n==1){
		printf("%c\n",s);
		return 0;
	}
	ch=s+n-1;
	
		for(j=1;j<=n-1;j++)
		    printf(" ");
		for(j=1;j<=n;j++){
			printf("%c",(ch-'A')%26+'A');
			ch++;
		}
		printf("\n");     //µÚÒ»ÐÐ
	for(i=2;i<=n-1;i++){
		for(j=1;j<=n-i;j++)
		    printf(" ");
		printf("%c",(s+n-i-'A')%26+'A');
		for(j=1;j<=n-4+2*i;j++)
		    printf(" ");
		printf("%c\n",(s+2*n+i-3-'A')%26+'A');
	} 
	for(j=1;j<=3*n-2;j++)
	    printf("%c",(s+j-1-'A')%26+'A');
	printf("\n");
	return 0;
}
