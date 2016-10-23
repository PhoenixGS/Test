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

int vet[300000];
int val[300000];
int next[300000];
int head[300000];
int Xor[300000];
int father[300000];
int b[200000 * 31][2];
int n;
int now;
int edgenum;

void add(int u, int v, int cost)
{
    edgenum++;
    vet[edgenum] = v;
    val[edgenum] = cost;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

void dfs(int u)
{
    Rep(i, u)
    {
        if (vet[i] != father[u])
        {
            father[vet[i]] = u;
            Xor[vet[i]] = Xor[u] ^ val[i];
            dfs(vet[i]);
        }
    }
}

void build(int u, int x)
{
    per(i, 30, 0)
    {
        int t = (x >> i) & 1;
        if (! b[u][t])
        {
            now++;
            b[u][t] = now;
        }
        u = b[u][t];
    }
}

int find(int u, int x)
{
    int ans = 0;
    per(i, 30, 0)
    {
        int t = (x >> i) & 1;
        if (b[u][t ^ 1])
        {
            u = b[u][t ^ 1];
            ans += 1 << i;
        }
        else
        {
            u = b[u][t];
        }
    }
    return ans;
}

int main()
{
    edgenum = 0;
    n = read();
    rep(i, 2, n)
    {
        int x = read(), y = read(), z = read();
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1);
    now = 1;
    rep(i, 1, n)
    {
        build(1, Xor[i]);
    }
    int ans = 0;
    rep(i, 1, n)
    {
        ans = max(ans, find(1, Xor[i]));
    }
    cout << ans << endl;
    return 0;
}
