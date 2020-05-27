#include"stdio.h"
#include<stdlib.h>
typedef struct HTNode
{
	int weight,parent,lchild,rchild;
} HTree, *HuffmanTree;;
int w[10000];
void select(HuffmanTree &HT, int i,int * s1,int * s2)
{
    int flag = 1200000000;
    int j;
    *s1=0;*s2=0;
	for (j = 0; j <= i; j++)
	{
		if (HT[j].parent == 0 && HT[j].weight < flag)
		{
			*s1 = j;
			flag = HT[j].weight;
		}
	}	
	flag = 1200000000;
	for (j = 0; j <= i; j++)
	{
		if (HT[j].parent == 0 && HT[j].weight < flag)
	    {
			if (j != *s1)
		    {
				*s2 = j;
				flag = HT[j].weight;
			}
		}	
	}
}  

void build_HT(HuffmanTree &HT, int *w, int n)
{
	int m;
	int i;
	int s1,s2;
	HuffmanTree p;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w)
		*p = { *w, 0, 0, 0 };
	for (i = n; i < m; ++i)
	{
		select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
int visit(HuffmanTree &HT,int n,int depth)
{
	if(HT[n].lchild==0&&HT[n].rchild==0)
	    if(depth==0)
	        return HT[n].weight;
	    else
	        return HT[n].weight*depth;
	else
	    return visit(HT,HT[n].lchild,depth+1)+visit(HT,HT[n].rchild,depth+1);
}
int main()
{
	int N;
	scanf("%d",&N);
	HuffmanTree HT;
	for (int i = 0; i < N; i++)
	    scanf("%d", &w[i]);
	build_HT(HT,w,N);
	printf("WPL=%d\n",visit(HT,2*N-2,0));
}
