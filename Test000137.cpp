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
ll pp = 110119;
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

ll b[200000];
ll inv[200000];
pair<ll, ll> q[200000];
ll dp[200000][3];

ll C(ll n, ll m)
{
    if (n < m)
    {
        return 0;
    }
    if (! m || n == m)
    {
        return 1;
    }
    return b[n] * inv[n - m] % pp * inv[m] % pp;
}

ll lucas(ll n, ll m)
{
    if (! n)
    {
        return 1;
    }
    return C(n % pp, m % pp) * lucas(n / pp, m / pp) % pp;
}

ll work(ll n, ll m)
{
    if ((n + m - 2) % 3)
    {
        return 0;
    }
    ll t = (n + m - 2) / 3;
    if (1 + t > n || 1 + t > m)
    {
        return 0;
    }
    ll x = n - 1 - t;
    return lucas(t, x);
}

int main()
{
    b[0] = 1;
    rep(i, 1, pp)
    {
        b[i] = b[i - 1] * i % pp;
    }
    rep(i, 0, pp)
    {
        inv[i] = powmod(b[i], pp - 2, pp);
    }
    ll cas = 0;
    ll n, m, k;
    while (scanf("%lld", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        m = read();
        k = read();
        rep(i, 1, k)
        {
            q[i].fi = read(), q[i].sc = read();
        }
        q[0].fi = q[0].sc = 1;
        sort(q, q + k + 1);
        q[k + 1].fi = n;
        q[k + 1].sc = m;
        dp[0][1] = 1;
        rep(i, 0, k)
        {
            rep(j, 0, 1)
            {
                rep(z, i + 1, k + 1)
                {
                    dp[z][j ^ 1] = (dp[z][j ^ 1] + dp[i][j] * work(q[z].fi - q[i].fi + 1, q[z].sc - q[i].sc + 1)) % pp;
                }
            }
        }
        cas++;
        printf("Case #%d: ", cas);
        cout << mo(dp[k + 1][0] - dp[k + 1][1], pp) << endl;
    }
    return 0;
}
