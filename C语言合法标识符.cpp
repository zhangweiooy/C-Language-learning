#include"stdio.h"
int main()
{
    int n;
    char garbage;
    scanf("%d%c",&n,&garbage);        //思考一下为什么有一个垃圾值 
    while(n--)
    {
    	char ch;
    	int adress=0;
    	int ans=0;
    	scanf("%c",&ch);
    	while(ch!='\n')           //为什么可以以\n作为跳出循环的判断条件 
    	{
    		if(adress==0)        //判断标识符第一位，只能是字母或者下划线 
    		{
    			if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')&&ch!='_') ans=1;
    		}
    		else               //判断其他位， ，只能是字母或者下划线或数字 
    		{
    			if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')&&(ch<'0'||ch>'9')&&ch!='_') ans=1;
    		}
    		adress++;
    		scanf("%c",&ch);
    	}
    	if(ans==1) printf("no\n");
    	else printf("yes\n");
    }
    return 0;
}
