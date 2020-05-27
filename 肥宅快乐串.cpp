#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char t[]="fattyhappy",a[2000],temp[10];
int T,i,j,al,count,dif[2],flag1,flag2;
void exchange(int p,int q)
{
	char gar;
	gar=temp[p];
	temp[p]=temp[q];
	temp[q]=gar;
	return ;
}
int main()
{
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		gets(a);
		al=strlen(a);
		flag1=flag2=0;
		for(i=0;i<=al-10;i++)
		{
			strncpy(temp,a+i,10);
			count=0;
		    dif[1]=0;dif[2]=0;
			if(strcmp(temp,t)==0)
			{
				printf("%d %d\n",3+i,4+i);
				goto k;
			}
			for(j=0;j<10;j++)
			{ 
			    if(count<2)
		            if(temp[j]!=t[j])
		            {
		            	dif[count]=j;  //记录不同处下标 
				    	count++;
				    }
			}
			if(count==1)     //一处不同
			{
				for(j=0;j<i;j++)
				{
					if(a[j]==t[dif[0]])
					{   
					    flag1=1;
					    printf("%d %d\n",j+1,dif[0]+i+1);
					    goto k;
					}
				}
				if(flag1==0)
				    for(j=i+10;j<al;j++)
				    {
				    	if(a[j]==t[dif[0]])
					    {   
					        flag1=1;
					        printf("%d %d\n",dif[0]+i+1,j+1);
					        goto k;
					    }
					}
			 } 
			if(count==2)    //两处不同
			{
				exchange(dif[0],dif[1]); 
				if(strcmp(temp,t)==0)
				{
					flag2=1;
					printf("%d %d\n",dif[0]+i+1,dif[1]+i+1);
					goto k;
				}
			} 
		}
		if(flag1==0&&flag2==0)
		    printf("-1\n");
		k:  ;
	}
 } 
