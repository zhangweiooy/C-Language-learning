#include"stdio.h"
int main()
{
    int n;
    char garbage;
    scanf("%d%c",&n,&garbage);        //˼��һ��Ϊʲô��һ������ֵ 
    while(n--)
    {
    	char ch;
    	int adress=0;
    	int ans=0;
    	scanf("%c",&ch);
    	while(ch!='\n')           //Ϊʲô������\n��Ϊ����ѭ�����ж����� 
    	{
    		if(adress==0)        //�жϱ�ʶ����һλ��ֻ������ĸ�����»��� 
    		{
    			if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')&&ch!='_') ans=1;
    		}
    		else               //�ж�����λ�� ��ֻ������ĸ�����»��߻����� 
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
