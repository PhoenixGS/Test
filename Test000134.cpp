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

int n, ans;
int x[2000];
int X[2000];
int Y[2000];

void dfsX(int t, int k)
{
    if (k > n)
    {
        ans = max(ans, t - 1);
        return;
    }
    dfsX(t, k + 1);
    bool F = true;
    if (t % 2 == 0)
    {
        if (x[k] <= X[t / 2])
        {
            F = false;
        }
    }
    if (t % 3 == 0)
    {
        if (X[t / 3 * 2] <= x[k])
        {
            F = false;
        }
    }
    if (F)
    {
        X[t] = x[k];
        dfsX(t + 1, k + 1);
    }
}

void dfsY(int t, int k)
{
    if (k > n)
    {
        ans = max(ans, t - 1);
        return;
    }
    dfsY(t, k + 1);
    bool F = true;
    if (t % 2 == 0)
    {
        if (x[k] >= Y[t / 2])
        {
            F = false;
        }
    }
    if (t % 3 == 0)
    {
        if (Y[t / 3 * 2] >= x[k])
        {
            F = false;
        }
    }
    if (F)
    {
        Y[t] = x[k];
        dfsY(t + 1, k + 1);
    }
}

int main()
{
    n = read();
    rep(i, 1, n)
    {
        x[i] = read();
    }
    ans = 0;
    X[0] = 0;
    dfsX(1, 1);
    Y[0] = 1000000000;
    dfsY(1, 1);
    cout << ans << endl;
    return 0;
}
