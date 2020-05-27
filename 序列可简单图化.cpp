#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5+1;
int N, a[maxn];
LL s[maxn];
inline void init() {
    memset(s, 0, sizeof(s));
}
int main()
{
        scanf("%d", &N); {
            init();
            for (int i=1; i<=N; ++i) {
                scanf ("%d", &a[i]);
                a[i] = -a[i];
            }
            sort(a+1, a+N+1);
            for (int i=1; i<=N; ++i) {
                s[i] = s[i-1]-a[i];
            }
            if (s[N]%2==1) {
                printf ("no\n");
                return 0;
            }
            bool flag = true;
            for (int r=1; r<=N; ++r) {
                int pos = upper_bound(a+r+1, a+N+1, -r)-a;
                if (s[r]> 1LL*r*(r-1)+  s[N]-s[pos-1]+  1LL*r*(pos-r-1)) {
                    flag = false;
                    break;
                }
            }
            printf ("%s\n", flag ? "yes" : "no");
        }
    
    return 0;
}
