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

struct node
{
    int x, id;
};

bool comp(node x, node y)
{
    return x.x > y.x;
}

int n, k;
int T_T[10000];
int f[10000];
node x[10000];

int main()
{
    n = read();
    k = read();
    rep(i, 1, n)
    {
        x[i].x = read();
        x[i].id = i;
    }
    sort(x + 1, x + n + 1, comp);
    rep(i, 1, n)
    {
        T_T[x[i].id] = (i - 1) / k + 1;
        f[i] = 1;
    }
    per(i, n - 1, 1)
    {
        per(j, n, i + 1)
        {
            if (T_T[i] >= T_T[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int ans = 0;
    rep(i, 1, n)
    {
        ans = max(ans, f[i]);
    }
    cout << n - ans << endl;
    return 0;
}
