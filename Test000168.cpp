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
    int u, v, cost;
};

int len[100][100];
int tmp[100];
node T[10000];
ll ansup, ansdown;
int n, m;
int f[100];
int ans[100];
int x[100];

bool comp(node x, node y)
{
    return x.cost < y.cost;
}

int findfather(int x)
{
    if (x == f[x])
    {
        return x;
    }
    return f[x] = findfather(f[x]);
}

void check()
{
    int last = 0;
    rep(i, 1, m)
    {
        rep(j, 1, m)
        {
            if (len[tmp[i]][tmp[j]])
            {
                last++;
                T[last].u = i;
                T[last].v = j;
                T[last].cost = len[tmp[i]][tmp[j]];
            }
        }
    }
    rep(i, 1, n)
    {
        f[i] = i;
    }
    sort(T + 1, T + last + 1, comp);
    ll tup = 0;
    rep(i, 1, last)
    {
        int xx = findfather(T[i].u);
        int yy = findfather(T[i].v);
        if (xx != yy)
        {
            f[xx] = yy;
            tup = tup + T[i].cost;
        }
    }
    ll tdown = 0;
    rep(i, 1, m)
    {
        tdown = tdown + x[tmp[i]];
    }
    //cout << tup << " " << tdown << endl;
    if (tup * ansdown < ansup * tdown)
    {
        //cout << "X" << endl;
        ansup = tup;
        ansdown = tdown;
        rep(i, 1, m)
        {
            ans[i] = tmp[i];
        }
    }
}

void dfs(int t, int k)
{
    if (t > m)
    {
        check();
        return;
    }
    for (int i = k + 1; i <= n && n - i + 1 >= m - t + 1; i++)
    {
        tmp[t] = i;
        dfs(t + 1, i);
    }
}

int main()
{
    n = read();
    m = read();
    rep(i, 1, n)
    {
        x[i] = read();
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            len[i][j] = read();
            len[j][i] = len[i][j];
        }
    }
    ansup = 1000000000;
    ansdown = 1;
    dfs(1, 0);
    rep(i, 1, m - 1)
    {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[m]);
    return 0;
}
