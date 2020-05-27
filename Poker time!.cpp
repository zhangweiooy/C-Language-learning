#include"stdio.h"
#include"string.h"
char a[3][3],b[3][3];
int judge( )
{
	int i;
	for(i=0;i<3;i++)
	{
		if(a[i][1]>='A'&&a[i][1]!='A'&&a[i][1]!='J'&&a[i][1]!='Q'&&a[i][1]!='K')
		return 0;
		if(b[i][1]>='A'&&b[i][1]!='A'&&b[i][1]!='J'&&b[i][1]!='Q'&&b[i][1]!='K')
		return 0;
	}                                             //判断不合法的牌 
	if(strcmp(a[1],a[0])==0||strcmp(a[0],a[2])==0||strcmp(a[1],a[2])==0)
	    return 0;
	if(strcmp(b[1],b[0])==0||strcmp(b[0],b[2])==0||strcmp(b[1],b[2])==0)
	    return 0;
	return 1;
}
void exchange(char m[],char n[])
{
	char f[3];
	strcpy(f,n);
	strcpy(n,m);
    strcpy(m,f);
    return ;
}                       //交换 
void sort()
{
    int i,j,max;
    for(i=0;i<3;i++)
    {
    	if(a[i][0]=='H')
    	    a[i][0]='d';
    	if(a[i][0]=='S')
    	    a[i][0]='c';
    	if(a[i][0]=='D')
    	    a[i][0]='b';
    	if(a[i][0]=='C')
    	    a[i][0]='a';
    	if(a[i][1]=='1')
    	    a[i][1]='9'+1;
    	if(a[i][1]=='J')
    	    a[i][1]='9'+2;
    	if(a[i][1]=='Q')
    	    a[i][1]='9'+3;
    	if(a[i][1]=='K')
    	    a[i][1]='9'+4;
    	if(a[i][1]=='A')
    	    a[i][1]='9'+5;
	}
	for(i=0;i<3;i++)
	{
		max=i;
		for(j=i+1;j<3;j++)
		    if(strcmp(a[max],a[j])<0)
		        max=j;
		if(max!=i)
		    exchange(a[i],a[max]);
	} 
	for(i=0;i<3;i++)
    {
    	if(b[i][0]=='H')
    	    b[i][0]='d';
    	if(b[i][0]=='S')
    	    b[i][0]='c';
    	if(b[i][0]=='D')
    	    b[i][0]='b';
    	if(b[i][0]=='C')
    	    b[i][0]='a';
    	if(b[i][1]=='1')
    	    b[i][1]='9'+1;
    	if(b[i][1]=='J')
    	    b[i][1]='9'+2;
    	if(b[i][1]=='Q')
    	    b[i][1]='9'+3;
    	if(b[i][1]=='K')
    	    b[i][1]='9'+4;
    	if(b[i][1]=='A')
    	    b[i][1]='9'+5;
	}
	for(i=0;i<3;i++)
	{
		max=i;
		for(j=i+1;j<3;j++)
		    if(strcmp(b[max],b[j])<0)
		        max=j;
		if(max!=i)
		    exchange(b[i],b[max]);
	}
    return ;
}                                    //排序 
int main()
{
    char winner='a';
	int i,j;
	for(i=0;i<3;i++)
	    scanf("%s",a[i]);
	for(j=0;j<3;j++)
	    scanf("%s",b[j]);
	if(judge( )==0)
	{
	    printf("Input Error!\n");
		return 0; 
	} 
	sort();
	if(strcmp(a[0],b[0])<0)
        winner='B';
    if(strcmp(a[0],b[0])>0)
        winner='A';
    if(strcmp(a[0],b[0])==0)
    {
    	if(strcmp(a[1],b[1])<0)
            winner='B';
        if(strcmp(a[1],b[1])>0)
            winner='A';
        if(strcmp(a[1],b[1])==0)
        {
    	    if(strcmp(a[2],b[2])<0)
                winner='B';
            if(strcmp(a[2],b[2])>0)
                winner='A';
            if(strcmp(a[2],b[2])==0)
			    winner='X';    
	    }
	}
	for(i=0;i<3;i++)
	{
	    if(b[i][0]=='d')
            b[i][0]='H';
   	    if(b[i][0]=='c')
    	    b[i][0]='S';
        if(b[i][0]=='b')
   	        b[i][0]='D';
        if(b[i][0]=='a')
            b[i][0]='C';
        if(b[i][1]=='9'+1)
            b[i][1]='1';
        if(b[i][1]=='9'+2)
            b[i][1]='J';
        if(b[i][1]=='9'+3)
   	        b[i][1]='Q';
        if(b[i][1]=='9'+4)
            b[i][1]='K';
        if(b[i][1]=='9'+5)
            b[i][1]='A';
            
        if(a[i][0]=='d')
            a[i][0]='H';
   	    if(a[i][0]=='c')
    	    a[i][0]='S';
        if(a[i][0]=='b')
   	        a[i][0]='D';
        if(a[i][0]=='a')
            a[i][0]='C';
        if(a[i][1]=='9'+1)
            a[i][1]='1';
        if(a[i][1]=='9'+2)
            a[i][1]='J';
        if(a[i][1]=='9'+3)
   	        a[i][1]='Q';
        if(a[i][1]=='9'+4)
            a[i][1]='K';
        if(a[i][1]=='9'+5)
            a[i][1]='A';
    }
    
    

    printf("Winner is %c!\n",winner);
    printf("A: %s %s %s\n",a[0],a[1],a[2]);
    printf("B: %s %s %s\n",b[0],b[1],b[2]);
    return 0;
}
