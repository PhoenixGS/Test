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

//边表
//复杂度:O(1)
//初始化:edgenum, head

const int maxn = 1010;
const int maxm = 1000010;

int n, m;
int edgenum;
int vet[maxm];
int val[maxm];
int next[maxm];
int head[maxn];

void add(int u, int v, int cost)
{
    edgenum++;
    vet[edgenum] = v;
    val[edgenum] = cost;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

bool flag[maxn];
int dis[maxn];
priority_queue<pr, vector<pr>, greater<pr> > Q;

int Dijkstra(int s)
{
    rep(i, 1, n)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    Q.push(mp(0, s));
    while (! Q.empty())
    {
        pr t = Q.top();
        Q.pop();
        int u = t.sc;
        if (flag[u])
        {
            continue;
        }
        Rep(i, u)
        {
            int v = vet[i];
            if (dis[u] + val[i] < dis[v])
            {
                dis[v] = dis[u] + val[i];
                Q.push(mp(dis[v], v));
            }
        }
    }
}

int main()
{
    n = read();
    m = read();
    while (m--)
    {
        int u = read();
        int v = read();
        int cost = read();
        add(u, v, cost);
        add(v, u, cost);
    }
    Dijkstra(1);
    cout << dis[n] << endl;
    return 0;
}
