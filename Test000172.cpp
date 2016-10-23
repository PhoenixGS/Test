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
int st[20];
ll T[500][10];

int main()
{
	n = read();
	rep(i, 1, n)
	{
		int x;
		scanf("%s%d", st, &x);
		T[st[0]][mo(x, 7)]++;
	}
	ll ans = 0;
	rep(B, 0, 6)
	{
		rep(E, 0, 6)
		{
			rep(S, 0, 6)
			{
				rep(I, 0, 6)
				{
					rep(G, 0, 6)
					{
						rep(O, 0, 6)
						{
							rep(M, 0, 6)
							{
								if ((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O) % 7 == 0)
								{
									ans += T['B'][B] * T['E'][E] * T['S'][S] * T['I'][I] * T['G'][G] * T['O'][O] * T['M'][M];
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
