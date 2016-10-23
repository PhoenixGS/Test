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

int n, m;
char st[2000];
int l[2000];
int r[2000];
int S[2000];

int main()
{
    n = read();
    m = read();
    rep(i, 1, n)
    {
        scanf("%s", st);
        l[i] = m + 1;
        r[i] = 0;
        rep(j, 1, m)
        {
            if (st[j - 1] == 'J' || st[j - 1] == 'Z')
            {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        }
        S[i] = S[i - 1];
        if (r[i] == 0)
        {
            l[i] = r[i] = -1;
        }
        else
        {
            S[i]++;
        }
        //printf("%d %d\n", i, S[i]);
    }
    int T = n;
    int now = 0;
    int k = 1;
    int ans = 0;
    while (S[T])
    {
        if (l[T] == -1)
        {
            ans++;
            T--;
            continue;
        }
        if (now == 0)
        {
            if (l[T] < k)
            {
                ans += k - l[T];
                k = l[T];
            }
            ans += r[T] - k;
            k = r[T];
            ans++;
        }
        if (now == 1)
        {

            if (r[T] > k)
            {
                ans += r[T] - k;
                k = r[T];
            }
            ans += k - l[T];
            k = l[T];
            ans++;
        }
        now = 1 - now;
        //printf("%d %d %d %d %d\n", T, ans, k, l[T], r[T]);
        T--;
    }
    cout << ans - 1 << endl;
    return 0;
}
