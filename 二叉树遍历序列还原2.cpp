#include<stdio.h>
#include<string.h>
char t1[60],t2[60];
int p;
int pos[255];
char tree[255][2];
int cou;
void deal(int l,int r,char head,int p)
{
     int m,tmp;
     if(p==0||cou>1000) 
	     return ;
     m=pos[head];
     tmp=pos[t2[p-1]];
     if(tmp<l) 
	     return ;
     if(m<tmp) 
	     tree[head][1]=t2[p-1];
     if(p-(r-m)-1>=0)
	 {
         tmp=pos[t2[p-(r-m)-1]];
         if(tmp<l) 
		     return ;
         if(m>tmp) 
	         tree[head][0]=t2[p-(r-m)-1];
     }
     cou++;
     deal(m+1,r,t2[p-1],p-1);
     deal(l,m-1,t2[p-(r-m)-1],p-(r-m)-1);
}
 
int main()
{
    cou=0;
    scanf("%s",t1);
    scanf("%s",t2);
    int len,i,j,nn=1,tmp[2][100],t=1,num;
    char head;
    len=strlen(t1);
    head=t2[len-1];
    p=len-1;
    memset(tree,0,sizeof(tree));
    for(i=0;i<len;i++) 
	    pos[t1[i]]=i;
    deal(0,len-1,head,len-1);
    tmp[1][0]=head;
    num=0;
    while(nn){
        for(i=0;i<nn;i++)
		{
            head=tmp[t&1][i];
            printf("%c",head);
            if(tree[head][0]) tmp[!(t&1)][num++]=tree[head][0];
            if(tree[head][1]) tmp[!(t&1)][num++]=tree[head][1];
        }
        nn=num;
        num=0;
        t++;
    }
    printf("\n");
    return 0;
}
