#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int max(int x,int y)
{
	if(x>y)
	    return x;
	else
	    return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
    char a[200000],b[200000]; 
	int aa[200000]={0},bb[200000]={0};    
    int al=0,bl=0,i,j,n;
    scanf("%s%s",&a,&b);
    al=strlen(a);
    bl=strlen(b);
    for(i=al-1;i>=0;i--)
    {
        aa[al-1-i]=a[i]-'0';
	}
	for(i=bl-1;i>=0;i--)
	{
		bb[bl-1-i]=b[i]-'0';
	}
	for(i=0;i<=max(al,bl);i++)
	{
		aa[i]+=bb[i];
		if(aa[i]>=2)
		{
		    aa[i]-=2;
		    aa[i+1]++;
	    }
	}
	i=max(al,bl);
	while(aa[i]==0)
	{
		i--;
		if(i<0)
		{
			i=0;
			break;
		}
	}
	for(j=1;j<=i+3-al;j++)  
    {  
        printf(" ");  
    }  
    printf("%s\n",a);  
    printf("+");  
    for(j=1;j<=i+2-bl;j++)  
    {  
        printf(" ");  
    }  
    printf("%s\n",b);  
    for(j=1;j<=i+3;j++)  
    {  
        printf("-");  
    } 
    printf("\n  ");
	for(;i>=0;i--)
	    printf("%d",aa[i]);
	printf("\n");
    }
}
