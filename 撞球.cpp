#include<stdio.h> 
#include<string.h> 
#include<math.h> 
int main() 
{char a[2000];
int w,l,x0,y0,x1,y1,i,k,r=0,f=0,n=0,m=0;
double c,d,s; scanf("%d%d",&w,&l);
scanf("%d%d",&x0,&y0);
scanf("%d%d",&x1,&y1);
scanf("%s",a); 
k=strlen(a);
for(i=0;i<k;i++) 
{if(a[i]=='R'||a[i]=='L') 
m++; 
if(a[i]=='F'||a[i]=='B') 
n++;} 
for(i=0;i<k;i++) 
{if(a[i]=='R') 
r=1;


if(a[i]=='L') r=2; 
if(r>0) break;} 
for(i=0;i<k;i++) 
{if(a[i]=='F') 
f=1; 
if(a[i]=='B') 
f=2; 
if(f>0) 
break;} 
if(m%2==0) 
d=m*w+(x0-x1)*pow(-1,r); 
else d=m*w+w-x0-x1; 
if(n%2==0) 
c=n*l+(-y0+y1)*pow(-1,f); 
else c=n*l-l+y0+y1; 
s=sqrt(pow(d,2)+pow(c,2)); 
printf("%.4f\n",s);}

