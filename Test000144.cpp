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

int x[200];
ll s[200];
ll f[200][200];
int n;

int main()
{
    n = read();
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            f[i][j] = INF;
        }
    }
    rep(i, 1, n)
    {
        x[i] = read();
        s[i] = s[i - 1] + x[i];
        f[i][i] = 0;
    }
    rep(len, 3, n)
    {
        rep(first, 1, n - len + 1)
        {
            int last = first + len - 1;
            rep(sec, first, last - 2)
            {
                rep(thi, sec, last - 1)
                {
                    f[first][last] = min(f[first][last], f[first][sec] + f[sec + 1][thi] + f[thi + 1][last] + (s[sec] - s[first - 1]) * (s[thi] - s[sec]) * (s[last] - s[thi]));
                    //printf("%d %d %d %d %d\n", first, sec, thi, last, f[first][last]);
                }
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
