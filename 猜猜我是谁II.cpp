#include<stdio.h> 
#include"stdlib.h" 
int main() 
{
    FILE * p;
	int l,i;
	char file[30],s[20];
	scanf("%s",file); 
	scanf("%d",&l); 
	if((p=fopen(file,"r"))==NULL) 
	{
	    printf("File Name Error.\n");
		exit(0);
	} 
	
    for(i=0;i<l;i++) 
	{
	    if(fgets(s,20,p)==NULL)
	    {
	    	printf("Line No Error.\n");
	    	exit(0);    
		}
	}
	printf("%s",s);
	fclose(p);
}
