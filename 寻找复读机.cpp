#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	 int n,m,i,j,flag=0,temp;
	 int id[2000];//不是复读机的为1 
	 char w[2000][105];
	 scanf("%d%d",&n,&m);
	 for(i=0;i<m;i++)
	 {
	 	scanf("%d %s",&temp,w[i]);
	 	if(i==0)
	 	{
	 		id[temp]=1;
		 }
		if(i>0)
		{
			if(strcmp(w[i],w[i-1])!=0)
			    id[temp]=1;
		 } 
	 }
	for(i=1;i<=n;i++)
	{
		if(id[i]!=1&&flag==0)
		 {
		   printf("%d",i);
	       flag=1;
	       continue;
		 }
		if(id[i]!=1&&flag==1)
		    printf(" %d",i);
	}
	if(flag==1)
	    printf("\n");
}
