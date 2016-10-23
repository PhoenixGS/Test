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

int k;
int x, y;

int main()
{
	k = read();
	rep(i, 1, k)
	{
		scanf("%d%d", &x, &y);
        ll x1 = x / 100;
        ll x2 = x / 10 % 10;
        ll x3 = x % 10;
        ll y1 = y / 100;
        ll y2 = y / 10 % 10;
        ll y3 = y % 10;
        for (ll X = 10; X <= 15000; X++)
        {
            ll T = x1 * X * X + x2 * X + x3;
            ll a = y1;
            ll b = y2;
            ll c = y3 - T;
            //cout << a << " " << b << " " << c << endl;
            if ((ll)sqrt(b * b - 4 * a * c) * (ll)sqrt(b * b - 4 * a * c) == b * b - 4 * a * c)
            {
                if ((-b + (ll)sqrt(b * b - 4 * a * c)) % (2 * a) == 0 && (-b + (ll)sqrt(b * b - 4 * a * c)) / (2 * a) >= 10)
                {
                    printf("%lld %lld\n", X, (-b + (ll)sqrt(b * b - 4 * a * c)) / (2 * a));
                    break;
                }
            }
        }
	}
    return 0;
}

