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

int t[1000];
int f[1000];

int main()
{
    t['`'] = 1;
    t['1'] = 1;
    t['Q'] = 1;
    t['A'] = 1;
    t['Z'] = 1;
    t['2'] = 2;
    t['W'] = 2;
    t['S'] = 2;
    t['X'] = 2;
    t['3'] = 3;
    t['E'] = 3;
    t['D'] = 3;
    t['C'] = 3;
    t['4'] = 4;
    t['R'] = 4;
    t['F'] = 4;
    t['V'] = 4;
    t['5'] = 4;
    t['T'] = 4;
    t['G'] = 4;
    t['B'] = 4;
    t['6'] = 5;
    t['Y'] = 5;
    t['H'] = 5;
    t['N'] = 5;
    t['7'] = 5;
    t['U'] = 5;
    t['J'] = 5;
    t['M'] = 5;
    t['8'] = 6;
    t['I'] = 6;
    t['K'] = 6;
    t[','] = 6;
    t['9'] = 7;
    t['O'] = 7;
    t['L'] = 7;
    t['.'] = 7;
    t['0'] = 8;
    t['P'] = 8;
    t[';'] = 8;
    t['/'] = 8;
    t['-'] = 8;
    t['['] = 8;
    t['\''] = 8;
    t['='] = 8;
    t[']'] = 8;
    string st;
    while (cin >> st)
    {
        rep(i, 0, st.length() - 1)
        {
            f[t[st[i]]]++;
        }
    }
    rep(i, 1, 8)
    {
        printf("%d\n", f[i]);
    }
    return 0;
}
