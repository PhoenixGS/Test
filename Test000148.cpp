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

int n, m, t;
int f[200000];
bool F[200000];

int main()
{
    n = read();
    m = read();
    t = read();
    memset(f, -1, sizeof(f));
    rep(i, 1, n)
    {
        int x = read();
        int y = read();
        if (f[y] == -1)
        {
            f[y] = x;
        }
    }
    int ans = 0;
    while (true)
    {
        F[t] = true;
        if (f[t] == -1)
        {
            break;
        }
        t = f[t];
        ans++;
        if (F[t])
        {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
