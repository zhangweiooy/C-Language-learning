#include"stdio.h"
long int ans=0;
int a[10000];
void merge(int left,int mid,int right) 
{ 
    int temp[right-left+1];//��ʱ���飬������ʱ��űȽϺ������ 
    int i=left,j=mid+1,k=0; 
    while(i<=mid&&j<=right)//�����Ƚ������������� 
    { 
        if(a[i]<=a[j]) 
        temp[k++] = a[i++]; //��벿��Ԫ��С���Ұ벿�ֵ�Ԫ�أ�����߸�Ԫ�ش�����ʱ���� 
        else 
        { 
            temp[k++] = a[j++]; 
            ans+=(mid-i+1);//ͳ�������ܺ��Ұ�߸�Ԫ�ع��ɵ�������� 
        } 
    } 
    while(i<=mid) 
        temp[k++]=a[i++]; 
    while(j<=right) 
        temp[k++]=a[j++]; 
    for(i=0; i < k;i++) 
        a[left + i] = temp[i];//����ʱ����ȡ���Ż�ԭ���� 
} 
void mergesort(int left,int right) 
{ 
    if(left >= right) 
        return ;
	int mid = (left+right)/2; 
    mergesort(left,mid);//�ݹ�������벿�� 
    mergesort(mid+1,right);//�ݹ������Ұ벿�� 
    merge(left,mid,right);//���������������ֺϲ� 
} 
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		    scanf("%d",&a[i]);
		mergesort(0,n-1);
		printf("%ld\n",ans);
	}
	return 0;
}


