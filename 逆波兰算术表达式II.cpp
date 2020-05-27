#include <stdio.h>  
#include <string.h>  
  
int tranfer(char *s)  
{  
    int k=1,result=0,len = strlen(s);  
    while(len--)  
    {  
        result += (s[len]-'0')*k;  
        k *= 10;  
    }  
  
    return result;  
}  
main( )  
{  
    char s[5000];  
    int j=0,num[100],k1=0,k2=0;  
    gets(s);
    while((scanf("%s",s))!=EOF)  
    {  
        if(s[0]>='0'&&s[0]<='9')  
        {
			num[j++] = tranfer(s);  
			k1++;
		}
        else  
        {  
            k2++;
			switch(s[0]){  
                case '+':  
                    num[j-2] += num[j-1];  
                    j--;  
                    break;  
                case '-':  
                    num[j-2] -= num[j-1];  
                    j--;  
                    break;  
                case '*':  
                    num[j-2] *= num[j-1];  
                    j--;  
                    break;  
                case '/':  
                    num[j-2] /= num[j-1];  
                    j--;  
                    break;  
            }  
        }  
        //printf("%d\n",num[0]);  
    }  
    printf("%d\n",num[0]);  
}  
