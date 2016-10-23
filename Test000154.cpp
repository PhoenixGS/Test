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

int T[300][300];
int f[2000][2000];

int main()
{
    T['A']['A'] = 5;
    T['A']['C'] = -1;
    T['A']['G'] = -2;
    T['A']['T'] = -1;
    T['A']['-'] = -3;
    T['C']['A'] = -1;
    T['C']['C'] = 5;
    T['C']['G'] = -3;
    T['C']['T'] = -2;
    T['C']['-'] = -4;
    T['G']['A'] = -2;
    T['G']['C'] = -3;
    T['G']['G'] = 5;
    T['G']['T'] = -2;
    T['G']['-'] = -2;
    T['T']['A'] = -1;
    T['T']['C'] = -2;
    T['T']['G'] = -2;
    T['T']['T'] = 5;
    T['T']['-'] = -1;
    T['-']['A'] = -3;
    T['-']['C'] = -4;
    T['-']['G'] = -2;
    T['-']['T'] = -1;
    string sx;
    cin >> sx;
    int lx = sx.length();
    sx = '#' + sx;
    string sy;
    cin >> sy;
    int ly = sy.length();
    sy = '#' + sy;
    rep(i, 1, lx)
    {
        f[i][0] = f[i - 1][0] + T[sx[i]]['-'];
    }
    rep(i, 1, ly)
    {
        f[0][i] = f[0][i - 1] + T['-'][sy[i]];
    }
    rep(i, 1, lx)
    {
        rep(j, 1, ly)
        {
            f[i][j] = max(f[i - 1][j - 1] + T[sx[i]][sy[j]], max(f[i][j - 1] + T['-'][sy[j]], f[i - 1][j] + T[sx[i]]['-']));
        }
    }
    cout << f[lx][ly] << endl;
    return 0;
}
