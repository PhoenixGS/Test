//head
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;

const double pi = acos(-1);

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, n, a) for (int i = n; i >= a; i--)
#define Rep(i, u) for (int i = head[u]; i; i = next[i])
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second

ld eps = 1e-9;
ll INF = 1000000007;
ll mo(ll a, ll pp) {if (a >= 0 && a < pp) return a; a %= pp; if (a < 0) a += pp; return a;}
ll powmod(ll a, ll b, ll pp) {ll ans = 1; for (; b; b >>= 1, a = mo(a * a, pp)) if (b & 1) ans = mo(ans * a, pp); return ans;}
ll lowbit(ll x) {return x & -x;}
ll read()
{
    ll ans = 0;
    char last = ' ', ch = getchar();
    while (ch < '0' || ch > '9') last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
    if (last == '-') ans = -ans;
    return ans;
}
//head

int n, m;
int x[1005][1005];
int s[1005][1005];
int que[1005][2];

int main()
{
    memset(x, -1, sizeof(x));
    n = read();
    m = read();
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            x[i][j] = read();
        }
    }
    ll ans = 0;
    rep(i, 1, n)
    {
        int head = 0;
        int tail = -1;
        rep(j, 1, m)
        {
            int total = 0;
            if (x[i][j] == x[i - 1][j] || x[i - 1][j] == -1)
            {
                s[i][j] = s[i - 1][j] + 1;
            }
            else
            {
                s[i][j] = 1;
            }
            if (x[i][j] != x[i][j - 1] && x[i][j - 1] != -1)
            {
                head = 0;
                tail = -1;
            }
            while (head <= tail && que[tail][0] > s[i][j])
            {
                total = total + que[tail][1];
                tail--;
            }
            tail++;
            que[tail][0] = s[i][j];
            que[tail][1] = total + 1;
            rep(i, head, tail)
            {
                ans += que[i][0] * que[i][1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
