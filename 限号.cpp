#include<bits/stdc++.h>
int vis[105][105],f[105][105];
int find(int c,int x)
{
    return f[c][x]==-1?x:f[c][x]=find(c,f[c][x]);
}
int max(int p,int q)
{
	if(p>q)
	    return p;
	else
	    return q;
 } 
int main()
{
    int n,m,k,i;
    scanf("%d%d",&n,&m);
    int u,v,a,b,c;
    memset(vis,0,sizeof(vis));
    memset(f,-1,sizeof(f));
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        vis[a][c]=1;
        vis[b][c]=1;
        int x=find(c,a);
        int y=find(c,b);
        if(x!=y)
          f[c][x]=y;
    }
    scanf("%d",&k);
    while(k--)
    {
        int ans=0;
        scanf("%d%d",&u,&v);
        for(i=1;i<=m;i++)
            if(vis[u][i]&&vis[v][i])
            {
                int x=find(i,u);
                int y=find(i,v);
                if(x==y)
                   ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}

