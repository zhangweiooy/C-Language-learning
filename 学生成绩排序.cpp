#include<string.h> 
#include <stdio.h> 
struct nn {char no[30];int num;}; 
typedef struct nn DATA; 
int main() 
{
    char str[30];
	int i,j,n,k;
	scanf("%d\n",&n);
	DATA b[n]; 
	for(i=0;i<n;i++) 
	{scanf("%s",&str);
	k=strlen(str)-1; 
	if(str[k-2]==',') b[i].num=(str[k]-'0')+(str[k-1]-'0')*10; 
	else b[i].num=(str[k]-'0')+(str[k-1]-'0')*10+(str[k-2]-'0')*100; 
	strcpy(b[i].no,str);} for(i=1;i<n;i++)for(j=0;j<n-i;j++) 
	if(b[j].num<b[j+1].num){strcpy(str,b[j].no);strcpy(b[j].no,b[j+1].no); 
	strcpy(b[j+1].no,str);k=b[j].num;b[j].num=b[j+1].num;b[j+1].num=k;} 
	for(i=0;i<n;i++) 
	printf("%s\n",b[i].no);
}
