#include<stdio.h> 
int main() 
{
    FILE * p;
	int l,i,flag=0;
	char file[30],s[20];
	scanf("%s",file); 
	if((p=fopen(file,"r"))==NULL) 
	{
	    printf("File Name Error.\n");
		exit(0);
	} 
	scanf("%d",&l); 
	if(l>4)
	{
	    flag=1;
		printf("Line No Error.\n");
	} 
	if(flag==0)
	{
	    for(i=0;i<l;i++) 
		{
		    fgets(s,17,p);
		}
		printf("%s",s);
	}
	fclose(p);
}
