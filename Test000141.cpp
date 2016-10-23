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

ll n;
string st;
int f[1000005][30];
int _;

int main()
{
    n = read();
    cin >> st;
    int len = st.length();
    st = '#' + st;
    rep(i, 1, len)
    {
        rep(j, 0, 25)
        {
            f[i][j] = f[i - 1][j];
        }
        f[i][st[i] - 65]++;
    }
    _ = read();
    while (_--)
    {
        ll l = read();
        char ch[10];
        scanf("%s", ch);
        ll ans = 0;
        ll Xa = (l * (l - 1) / 2) / len;
        ll Xb = (l % len * ((l - 1) % len)) / 2 % len;
        ll Ya = (l * (l + 1) / 2) / len;
        ll Yb = (l % len * ((l + 1) % len)) / 2 % len;
        ll T;
        if (Yb >= Xb)
        {
            T = Ya - Xa;
        }
        else
        {
            T = Ya - Xa - 1;
        }
        if (Xb == 0)
        {
            Xb = len;
            Xa--;
        }
        if (Yb == 0)
        {
            Yb = len;
            Ya--;
        }
        ans = T * (f[len][ch[0] - 65]);
        if (Yb < Xb)
        {
            ans += f[len][ch[0] - 65] - f[Xb][ch[0] - 65] + f[Yb][ch[0] - 65];
        }
        else
        {
            ans += f[Yb][ch[0] - 65] - f[Xb][ch[0] - 65];
        }
        cout << ans << endl;
    }
}
