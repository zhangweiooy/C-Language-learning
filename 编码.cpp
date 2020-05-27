#include<stdio.h> 
#include<stdlib.h> 
unsigned long f(unsigned long a,unsigned long b) 
{
    unsigned long c=1,i; 
	for(i=1;i<=a;i++) 
	{
	    c*=(b-i+1);
	    c=c/i;
	}                             //排列组合（C*·，从多少数中选几个顺序排列 
	return(c);
} 
unsigned long m(unsigned long a,unsigned long n) 
{
    unsigned long b=0,i; 
	for(i=1;i<=a;i++)
	{
	    b+=f(i,26);
	} 
	if(a==0)
	return 0;
	else 
	return b;
}
int main() 
{
    int n;
	scanf("%d\n",&n); 
	unsigned long i,j,k,length,a,d; 
	char b[27]; 
	while(n--)
	{ 
	    a=d=length=0;
		b[0]='a'-1; 
		for(j=1;j<28;j++)
		{   
		    scanf("%c",&b[j]); 
			if(b[j]=='\n')
			    break;
		    length++;
		} 
		for(j=0;j<=length;j++)
		{
            for(k=j+1;k<=length;k++)
		    { 
		        if(b[j]>=b[k])
			        d=1;
		    }
		} 
		if(d==1)
		    printf("0\n");
		else
		{
		    a+=m(length-1,26); 
			if(length>1)
			{
			    for(k='a';k<b[1];k++)
				    a+=f(length-1,'z'-k); 
				for(j=2;j<length;j++)
				{ 
				    for(k=b[j-1]+1;k<b[j];k++)
					{
					    a+=f(length-j,'z'-k);
					}
				} 
				a+=b[length]-b[length-1];
			} 
			else 
			    a+=b[1]-('a'-1);
			printf("%d\n",a);
		}
	}
	return 0;
}

