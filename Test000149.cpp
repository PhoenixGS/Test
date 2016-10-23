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

int n, m, maxx;
ll S, ans;
int l[300000], r[300000];
int w[300000], v[300000];
ll s[300000], t[300000];

ll calc(int mid)
{
	ll ans = 0;
    rep(i, 1, n)
	{
		s[i] = s[i - 1];
		t[i] = t[i - 1];
		if (w[i] >= mid)
		{
			s[i] += v[i];
			t[i]++;
		}
	}
    rep(i, 1, m)
	{
		ans += (t[r[i]] - t[l[i]  - 1]) * (s[r[i]] - s[l[i] - 1]);
	}
	return ans;
}

int main()
{
    cin >> n >> m >> S;
	rep(i, 1, n)
	{
        scanf("%d%d", &w[i], &v[i]);
        maxx = max(maxx, w[i]);
    }
	rep(i, 1, m)
	{
        scanf("%d%d", &l[i], &r[i]);
    }
	int l = 0;
    int r = maxx + 1;
    ans = INF * INF;
	while (l < r)
	{
		int mid = (l + r) / 2;
		ll t = calc(mid);
		ans = min(ans, abs(t - S));
		if (t <= S)
        {
            r = mid;
        }
		else
        {
            l = mid + 1;
        }
	}
	cout << ans << endl;
	return 0;
}
