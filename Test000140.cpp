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

int n;
int x[10000];

int main()
{
    x[0] = 6;
    x[1] = 2;
    x[2] = 5;
    x[3] = 5;
    x[4] = 4;
    x[5] = 5;
    x[6] = 6;
    x[7] = 3;
    x[8] = 7;
    x[9] = 6;
    n = read();
    rep(i, 10, 4000)
    {
        int tmp = i;
        while (tmp)
        {
            x[i] += x[tmp % 10];
            tmp /= 10;
        }
    }
    ll ans = 0;
    rep(i, 0, 2000)
    {
        rep(j, 0, 2000)
        {
            if (x[i] + x[j] + x[i + j] == n - 4)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
