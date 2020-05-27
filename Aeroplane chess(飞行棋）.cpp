#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010

double dp[N];
int nxt[N];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m), n+m) {
        memset(nxt, -1, sizeof(nxt));
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            nxt[u] = v;
        }
        memset(dp, 0, sizeof(dp));
        double dec = (double)1 / 6;
        for(int i = n - 1; i >= 0; i--) {
            if(nxt[i] != -1) {
                dp[i] = dp[nxt[i]]; //如果可以飞，就直接把上一步的值赋给它
                continue;
            }
            for(int j = 1; j <= 6; j++) {
                if(i + j <= n) {
                    dp[i] += dp[i + j] * dec; //不能飞的话，就掷骰子为1-6的概率都为1/6，递推
                }
            }
            dp[i]++; //走到下一步要+1
        }
        printf("%.4f\n", dp[0]);
    }
    return 0;
}
