//���ڴ��⣬�ɷ����������ֵĹ��ɣ��ڵ�n�г��ֵ����ֵĶ�����
//     ��ʽ�ĵ�nλ����1��������λ��0����˵ó������ 
#include"stdio.h"
#include"math.h"
int main()
{
	int a[10]={1},i,assist,n=0;
	for(i=1;a[i-1]!=0;i++)
	{
		scanf("%d",&a[i]);
	}
	assist=i-2;
	for(i=1;i<=assist;i++)
	{
		n=n+pow(2,(a[i]-1));
	}
	printf("%d\n",n);
}
