#include <stdio.h> 
#include <stdlib.h> 
int operation(char ch,int *k) 
{    
    switch (ch)
    {
	    case '+':return(*k +*(k+1)); 
	    case '-':return(*k-*(k+1)); 
		case '*':return(*k * *(k+1)); 
		case '/':return(*k / *(k+1)); 
		default:return 0;
		}
} 
int main() 
{
    int operation(char,int *); 
	static int number[50];
	int i=0;
	char sign[50],*p=sign; 
	gets(sign); 
	while(*p) {
	    if(*p<='9'&&*p>='0') 
		number[i++]=atoi(p); 
		else {
		    number[i-2]=operation(*p,&number[i-2]);
			i--; 
			} 
		for(p++;!(*p!=' '&&*(p-1)==' ')&&*p;p++);
	} 
	printf ("%d\n",number[0]); 
	return 0;
}
