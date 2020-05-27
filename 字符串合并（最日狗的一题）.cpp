#include"stdio.h"
int main()
{
	int i,j,k,judgea=0,judgeb=0;
	char a[100],b[100],d[200];
    gets(a);
    gets(b);
    if(a[0]=='\0')   {puts(b);return 0;}
    if(b[0]=='\0')   {puts(a);return 0;}
	for(i=0,j=0,k=0;judgea==0||judgeb==0;k++)
	{
		if(judgeb==1&&judgea!=1)    goto fuck;  
		if(a[i]<=b[j]&&judgea!=1)
	    {
		fuck:    
			d[k]=a[i];
	        i++;
			if(a[i]=='\0')
	        {
	        	i--;
	        	judgea=1;
			} 
		}
		else if(judgeb!=1)
		{
			d[k]=b[j];
			j++;
			if(b[j]=='\0')
			{
				j--;
				judgeb=1;
			}  
			
		}
    }
    d[k]='\0';
    puts(d);
}
