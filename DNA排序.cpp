#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<queue>
#include<cstdlib> 
using namespace std;
int n,m;
typedef struct p
{
    char String[52];
    int count;
}DNA;
DNA b[110];
int measure(int in)
{
    int i,j;
    int ans = 0;
    for (i=0; i<n-1; i++)
    {
        if ('A' == b[in].String[i])
        {
            continue;
        }
        for (j=i+1; j<n; j++)
        {
            if (b[in].String[i] > b[in].String[j])
            {
                ans++;
            }
        }
    }
    return ans;
}
int cmp(const void*c,const void*d)
{
	DNA* e1=(DNA *)c;
	DNA* e2=(DNA *)d;
	if(e1->count!=e2->count)
	    return e1->count - e2->count;
	else
	    return 0;
}
int main()
{
	int i,j,len;
	scanf("%d %d\n",&n,&m);
	
	for(i=0;i<m;i++)
	{
		gets(b[i].String);
		b[i].count=measure(i);
	}
	qsort(b,m,sizeof(b[0]),cmp);
	for(i=0;i<m;i++)
	    printf("%s\n",b[i].String);
	return 0;
}
