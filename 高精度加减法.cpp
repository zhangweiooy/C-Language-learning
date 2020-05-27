#include"stdio.h"
#include"string.h"
int negative(char a[],char b[])
{
	if(strlen(a)<strlen(b))
	    return -1;
	if(strlen(a)>strlen(b))
	    return 1;
	if(strlen(a)==strlen(b))
	{
	    if(strcmp(a,b)<0)
            return -1;
	   	if(strcmp(a,b)>0)
		   	return 1;
		return 0;
	}
	
}
int main()
{
	int t,i,j;
	
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char a[555]={'\0'},b[555]={'\0'},assist[1111],op;
		int m[555]={0},n[555]={0},judge=1;
		gets(assist);
		for(i=j=0;i<strlen(assist);i++)
		{
			if(assist[i]=='+'||assist[i]=='-')
			{
				op=assist[i];
				judge=2;
				continue;
			}
			if(judge==1)
			    a[i]=assist[i];
			
			if(judge==2)
			{
				b[j]=assist[i];
				j++;
			}
		}
		
		for(i=0;i<=strlen(a)-1;i++)
		    m[i]=a[strlen(a)-i-1]-'0';
		for(i=0;i<=strlen(b)-1;i++)
		    n[i]=b[strlen(b)-i-1]-'0';
		if(op=='-')
		{
			if(negative(a,b)<0)        
            {     
                printf("-");    
                for(i=0;i<strlen(b);i++)    
                {    
                    n[i]=n[i]-m[i];    
                    if(n[i]<0)    
                    {    
                        n[i]+=10;    
                        n[i+1]--;    
                    }    
                }    
                i=strlen(b)-1;    
                while(n[i]==0)
				{
					i--;
					if(i<0)
					{i=0;break;
					}
				}
                for(;i>=0;i--)    
                    printf("%d",n[i]);    
            }    
            else    
            {    
                for(i=0;i<strlen(a);i++)    
                {
				    m[i]=m[i]-n[i];
					if(m[i]<0)
					{
						m[i]+=10;
						m[i+1]--;
				    }   
					
                }
                i=strlen(a)-1;
				while(m[i]==0)
				{
					i--;
					if(i<0)
					{i=0;break;
					}
				}
				
				for(;i>=0;i--)    
                    printf("%d",m[i]);  
            }    
		}
		if(op=='+')
		{
			for(i=0;i<=(strlen(a)>strlen(b)?strlen(a):strlen(b));i++)
			{
				m[i]=m[i]+n[i];
				if(m[i]>9)
				{
					m[i]-=10;
					m[i+1]++;
				}
			}
			i=(strlen(a)>strlen(b)?strlen(a):strlen(b));
			while(m[i]==0)
				{
					i--;
					if(i<0)
					{i=0;break;
					}
				}
			for(;i>=0;i--)
			    printf("%d",m[i]);
		}
		printf("\n");
	}
	return 0;
}
