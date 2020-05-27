# include<cstdio>
# include<iostream>
# include<cstring>
using namespace std;
# define MAX 100
int Edge[MAX][MAX];
 
int main()
{
    int n;
    int a,b;
    cin>>n;
    memset( Edge,0,sizeof(Edge) );
    for(int i=0;i<n;i++ )
    for(int j=0;j<n;j++)
    {
        cin>>Edge[i][j];
    }
    for ( int i = 0;i < n;i++ )
    {
        a = 0;
		b = 0;
        for ( int j = 0;j < n;j++ )
        {
            a += Edge[i][j];
        }
        for ( int j = 0;j < n;j++ )
        {
            b += Edge[j][i];
        }
            cout<<a<<" "<<b<<endl;
    }
    return 0;
}
