#include<stdio.h> 
#include<string.h> 
int main()
{
    char a[1000][25],b[11000],x[10000]; 
	int c,d[1000],e[1000],i,j,k=0,w,z,s,y,m,n[1002],p=0,q,g; 
	static int P[1000];
	scanf("%d",&c);
	b[0]=' ';
	for(i=0;i<c;i++) 
	{
	    scanf("%s",a[i]);
		scanf("%s",x); 
		m=strlen(x);
		x[m]=' ';
		x[m+1]='\0'; 
		strcat(b,x);
	}
	m=strlen(b);
	for(i=0;i<m;i++){
	    if(b[i]==' '){
		    n[p]=i;p++;
		}
	} 
	for(i=0;i<c;i++){
	    d[i]=n[i+1]-n[i]-1;
	} 
	for(i=0;i<c;){
	    q=0;
		g=0;
		s=0;
		w=i; 
		for(j=0;j<c;j++){
		    if(P[j]==0&&i!=j){
		        if(d[w]==d[j]){
				    for(z=0;z<d[w];z++) {
					    if(b[n[w]+1+z]<b[n[j]+1+z]){
						    q++;break;
						} 
						if(b[n[w]+1+z]>b[n[j]+1+z]){
						    g++;break;
						}
					} 
					if(q==0&&g==0){
					    if(strcmp(a[w],a[j])>0) 
						    w=j;
					} 
					if(q>0)
					    w=j;
				} 
				if(d[w]<d[j])w=j;
			}
		}
		e[k]=w;
		k++;
		P[w]=1; 
		if(w==i){
		    for(z=i;z<c;z++){
			    if(P[z]==0){i=z;break;
			    }
	        }
		    for(y=0;y<c;y++) 
		        s+=P[y];
		    if(s==c) 
		    i=c;
		}
	}
	for(i=0;i<c;i++)
	    printf("%s\n",a[e[i]]);
}
