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

int f[200][200];
int x[200];
int y[200];
int n, m;

bool check(int times)
{
    memset(f, 0, sizeof(f));
    rep(i, 1, m)
    {
        f[0][i] = -1000000000;
    }
    rep(i, 1, n)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= j && k * x[i] <= times; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + (times - k * x[i]) / y[i]);
            }
        }
    }
    if (f[n][m] >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    n = read();
    m = read();
    rep(i, 1, n)
    {
        x[i] = read();
        y[i] = read();
    }
    int l = 0;
    int r = 50000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
