#include<stdio.h> 
#include<math.h> 
int main() 
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	    int m,x[100],y[100];
        int j,a,b,c;  
		double s,d=0;
        scanf("%d",&m); 
        for(j=0;j<m;j++) 
        {
		    scanf("%d",&x[j]);
            scanf("%d",&y[j]);
		}
        for(a=0;a<m-2;a++) 
            for(b=a+1;b<m-1;b++) 
                for(c=b+1;c<m;c++) 
                {
		    	    s=(double)((x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]))/2.0;
                    s=fabs(s);
                    if(s>d)
					    d=s;
				}
                printf("%.1f\n",d);
	}
}

