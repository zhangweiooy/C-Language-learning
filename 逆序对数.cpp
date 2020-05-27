#include"stdio.h"
long int ans=0;
int a[10000];
void merge(int left,int mid,int right) 
{ 
    int temp[right-left+1];//临时数组，用于临时存放比较后的数字 
    int i=left,j=mid+1,k=0; 
    while(i<=mid&&j<=right)//遍历比较左右两个部分 
    { 
        if(a[i]<=a[j]) 
        temp[k++] = a[i++]; //左半部分元素小于右半部分的元素，将左边该元素存入临时数组 
        else 
        { 
            temp[k++] = a[j++]; 
            ans+=(mid-i+1);//统计左半边能和右半边该元素构成的逆序对数 
        } 
    } 
    while(i<=mid) 
        temp[k++]=a[i++]; 
    while(j<=right) 
        temp[k++]=a[j++]; 
    for(i=0; i < k;i++) 
        a[left + i] = temp[i];//从临时数组取出放回原数组 
} 
void mergesort(int left,int right) 
{ 
    if(left >= right) 
        return ;
	int mid = (left+right)/2; 
    mergesort(left,mid);//递归排序左半部分 
    mergesort(mid+1,right);//递归排序右半部分 
    merge(left,mid,right);//将处理后的两个部分合并 
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


