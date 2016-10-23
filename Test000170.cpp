//head
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>

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

int edgenum;
int vet[10000];
int next[10000];
int head[10000];
int cost[10000];
int len[100][100];
int dis[100];
bool inque[100];
queue<int> que;
int n, m, k;
int flag[100];
int ans;

void add(int u, int v, int len)
{
    edgenum++;
    vet[edgenum] = v;
    cost[edgenum] = len;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

int spfa()
{
    rep(i, 1, n)
    {
        dis[i] = 1000000000;
    }
    while (! que.empty())
    {
        que.pop();
    }
    dis[1] = 0;
    que.push(1);
    inque[1] = true;
    while (! que.empty())
    {
        int u = que.front();
        que.pop();
        Rep(i, u)
        {
            int v = vet[i];
            int len = cost[i];
            if (dis[u] + len < dis[v])
            {
                dis[v] = dis[u] + len;
                if (! inque[v])
                {
                    inque[v] = true;
                    que.push(v);
                }
            }
        }
        inque[u] = false;
    }
    return dis[n];
}

bool check()
{
    edgenum = 0;
    memset(head, 0, sizeof(head));
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if ((! flag[i]) && (! flag[j]) && len[i][j])
            {
                add(i, j, 1);
            }
        }
    }
    int total = 0;
    rep(i, 1, n)
    {
        if (flag[i])
        {
            total++;
        }
    }
    if (spfa() <= k)
    {
        return false;
    }
    else
    {
        ans = min(ans, total);
        return true;
    }
}

void dfs(int t, int pre)
{
    if (check())
    {
        return;
    }
    if (pre == n - 1)
    {
        return;
    }
    rep(i, pre + 1, n - 1)
    {
        flag[i] = true;
        dfs(t + 1, i);
        flag[i] = false;
    }
}

int main()
{
    n = read();
    m = read();
    k = read();
    rep(i, 1, m)
    {
        int u = read();
        int v = read();
        len[u][v] = 1;
    }
    ans = 1000000000;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
