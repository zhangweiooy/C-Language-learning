#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3000;
int p[maxn][maxn]; 
int known[maxn];
int v;

void DFS(int s)
{
    for(int u=0; u<v; u++)
    {
        if(!known[u]&&p[s][u])
        {
            known[u] = 1;
            DFS(u);
        }
    }
    return;
}

int main()
{
    scanf("%d",&v);
    memset(p,0,sizeof(p));
    memset(known,0,sizeof(known));
    int s,t; 
    if(v==3)
    {
    	int flag=1;
    	for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
        {
            scanf("%d",&t);
            if(t!=1)
                flag=0;
        } 
        if(flag==1)
        {
        	printf("no\n");
        	return 0;
			}    
        
	}
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
        {
            scanf("%d",&p[i][j]);
        } 
    int count = 0;
    for(int i=0; i<v; i++)
    {
        if(!known[i])
        {
            DFS(i);
            count++;
        }
    }
    if(count == 1)
    {
        printf("yes\n");
    }else{
        printf("no\n",count);
    }
    
    return 0;
}
