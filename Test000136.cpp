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

ll l, r;
ll T_T[10000];
ll n[10000];
ll last;
ll ans;
ll N;

void make(ll k)
{
    if (k > r)
    {
        return;
    }
    if (k)
    {
        last++;
        T_T[last] = k;
    }
    make(k * 10 + 6);
    make(k * 10 + 8);
}

void dfs(int k, ll x, int kk)
{
    if (k == N + 1)
    {
        if (x == 1)
        {
            return;
        }
        ans += (r / x - (l - 1) / x) * kk;
        return;
    }
    dfs(k + 1, x, kk);
    ll y = n[k];
    ll t = __gcd(y, x);
    if (x / t <= (ld)r / y)
    {
        dfs(k + 1, x / t * y, kk * (-1));
    }
}

int main()
{
    l = read();
    r = read();
    last = 0;
    make(0);
    sort(T_T + 1, T_T + last + 1);
    ans = 0;
    N = 0;
    rep(i, 1, last)
    {
        bool F = false;
        rep(j, 1, i - 1)
        {
            if (T_T[i] % T_T[j] == 0)
            {
                F = true;
            }
        }
        if (! F)
        {
            N++;
            n[N] = T_T[i];
        }
    }
    rep(i, 1, N / 2)
    {
        swap(n[i], n[N - i + 1]);
    }
    dfs(1, 1, -1);
    cout << ans << endl;
    return 0;
}
