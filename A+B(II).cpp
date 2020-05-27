#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int p,int q)
{
	if(p>=q)
	    return p;
	else
	    return q;
}
int main()
{
	int az[2200]={0},ax[2200]={0},bz[2200]={0},bx[2200]={0},ansz[2200]={0},ansx[2200]={0},i,j,ad=0,bd=0,al,bl,azl,axl,bzl,bxl,anszl,ansxl;
	char a[4400],b[4400];
	gets(a);
	gets(b);
	al=strlen(a);
	bl=strlen(b);
	for(i=0;i<al;i++)
		if(a[i]=='.')
		    ad=i;
	for(i=0;i<bl;i++)
	    if(b[i]=='.')
	        bd=i;          //记录小数点位置 
	if(ad!=0)
	    azl=ad;
	else
	    azl=al;
	if(bd!=0)
	    bzl=bd;
	else
	    bzl=bl;
	axl=al-azl-1;
	bxl=bl-bzl-1;
	for(i=al-1,j=max(axl,bxl)-axl;i>ad;i--)
	{
		ax[j]=a[i]-'0';
		j++;
	}
	for(i=bl-1,j=max(axl,bxl)-bxl;i>bd;i--)
	{
		bx[j]=b[i]-'0';
		j++;
	}
	for(i=azl-1,j=0;i>=0;i--)
	{
		az[j]=a[i]-'0';
		j++;
	}
	for(i=bzl-1,j=0;i>=0;i--)
	{
		bz[j]=b[i]-'0';
		j++;
	}
	for(i=0;i<max(axl,bxl);i++)
	{
		ansx[i]+=ax[i]+bx[i];
		if(ansx[i]>9&&i!=max(axl,bxl)-1)
		{
			ansx[i]-=10;
		    ansx[i+1]+=1;
		}
		if(ansx[i]>9&&i==max(axl,bxl)-1)
		{
			ansx[i]-=10;
			ansz[0]+=1;
		}
	}
	for(i=0;i<max(azl,bzl);i++)
	{
		ansz[i]+=az[i]+bz[i];
		if(ansz[i]>9)
		{
			ansz[i]-=10;
			ansz[i+1]++;
		}
	}
	if(ansz[i]!=0)
	    anszl=i+1;
	else
	    anszl=i;
	while(ansz[i]==0)
	{
		i--;
		if(i<0)
		{
		    i=0;
		    anszl=i;
		    break;
		}
		anszl=i+1;		
	}
	if(anszl==0)
	    anszl=1;
	ansxl=max(axl,bxl);
	for(i=0;i<max(max(azl,bzl),anszl)+3-azl;i++)
	    printf(" ");
	printf("%s",a);
	for(i=0;i<max(axl,bxl)-axl;i++)
	    printf(" ");
	printf("\n");
	printf("+");
	for(i=0;i<max(max(azl,bzl),anszl)+3-bzl-1;i++)
	    printf(" ");
	printf("%s",b);
	for(i=0;i<max(axl,bxl)-bxl;i++)
	    printf(" ");
	printf("\n");
	for(i=0;i<max(max(azl,bzl),anszl)+max(axl,bxl)+4;i++)
	    printf("-");
	printf("\n");
	for(i=0;i<max(max(azl,bzl),anszl)+3-anszl;i++)
	    printf(" ");
	for(i=anszl-1;i>=0;i--)
	    printf("%d",ansz[i]);
	if(ad!=0||bd!=0)
	    printf(".");
	for(i=ansxl-1;i>=0;i--)
	    printf("%d",ansx[i]);
	printf("\n");
	    
}
