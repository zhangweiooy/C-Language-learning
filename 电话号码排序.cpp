#include<stdio.h>
#include<stdlib.h>
int transform(char a[])
{
	int i,flag,num=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='_')
		    continue;
		if(a[i]=='0')
		num=num*10+0;
		if(a[i]=='1')
		num=num*10+1;
		if(a[i]=='A'||a[i]=='B'||a[i]=='C'||a[i]=='2')
        num=num*10+2;
        if(a[i]=='D'||a[i]=='E'||a[i]=='F'||a[i]=='3')
        num=num*10+3;  
        if(a[i]=='G'||a[i]=='H'||a[i]=='I'||a[i]=='4')
        num=num*10+4;      
        if(a[i]=='J'||a[i]=='K'||a[i]=='L'||a[i]=='5')
        num=num*10+5;  
        if(a[i]=='M'||a[i]=='N'||a[i]=='O'||a[i]=='6')
        num=num*10+6;  
        if(a[i]=='P'||a[i]=='R'||a[i]=='S'||a[i]=='7')
        num=num*10+7;
        if(a[i]=='T'||a[i]=='U'||a[i]=='V'||a[i]=='8')
        num=num*10+8;
        if(a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='9')
        num=num*10+9;
	}
	return num;
}
int cmp(const void*c,const void*d)
{
	return *(int *)c - *(int *)d;
}
int main()
{
	int t,i,j,count,judge=0;
	char a[20];
	scanf("%d\n",&t);
	int b[100001]={0};
	for(i=0;i<t;i++)
	{
		gets(a);
		b[i]=transform(a);
	}
	b[t]=-10000;
	qsort(b,t,sizeof(b[0]),cmp);
	for(i=0;i<t;i++)
	{
		count=1;
		while(b[i]==b[i+1])
		{
			i++;
			count++;
		}
		if(count>1)
		{
			judge=1;
			printf("%03d-%04d %d\n",b[i]/10000,b[i]%10000,count);
		}
		
	}
	if(judge==0)
	{
		printf("No duplicates.\n");
	}
	return 0;
}
