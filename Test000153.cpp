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

int F[200000];
int x[200000];
int y[200000];

int main()
{
    int n = read();
    int minx = INF;
    int maxx = 0;
    rep(i, 1, n)
    {
        int h = read();
        minx = min(minx, h);
        maxx = max(maxx, h);
        F[h]++;
    }
    int last = 0;
    rep(i, minx, maxx)
    {
        if (F[i] > 0)
        {
            last++;
            x[last] = i;
            y[last] = F[i];
        }
    }
    int l = 1;
    int r = last;
    if (l == r)
    {
        printf("Slavko\n");
        printf("%d %d\n", x[l], x[r]);
        return 0;
    }
    while (true)
    {
        if (l + 1 == r)
        {
            printf("Slavko\n");
            printf("%d %d\n", x[l], x[r]);
            return 0;
        }
        if (l + 2 == r)
        {
            if (y[l] > y[r])
            {
                printf("Slavko\n");
                printf("%d %d\n", x[l], x[r - 1]);
                return 0;
            }
            if (y[l] <= y[r])
            {
                printf("Mirko\n");
                printf("%d %d\n", x[l + 1], x[r]);
                return 0;
            }
        }
        int tmp = min(y[l], y[r]);
        y[l] -= tmp;
        y[r] -= tmp;
        y[l + 1] += tmp;
        y[r - 1] += tmp;
        if (y[l] == 0)
        {
            l++;
        }
        if (y[r] == 0)
        {
            r--;
        }
    }
    return 0;
}
