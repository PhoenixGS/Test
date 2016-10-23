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

int x[2000][2000];
int n, m;

bool check(int l, int r, int key, int T_T)
{
    rep(i, l, r)
    {
        if (x[T_T][i] != key)
        {
            return false;
        }
    }
    return true;
}

int find(int l, int r, int key, int T_T)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r + 1) >> 1;
    if (check(l, mid, key, T_T))
    {
        return find(mid, r, key, T_T);
    }
    else
    {
        return find(l, mid - 1, key, T_T);
    }
}

int main()
{
    n = read();
    m = read();
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            x[i][j] = read();
        }
    }
    ll ans = 0;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            int last = m;
            int key = x[i][j];
            rep(k, i, n)
            {
                if (x[k][j] != key)
                {
                    break;
                }
                int lastT = find(j, last, key, k);
                ans += lastT - j + 1;
                last = min(last, lastT);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

