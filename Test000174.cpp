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

struct node
{
	int x, y;
};

int n, d;
node x[200000];
int T[200000];
int minx[200000];
int maxx[200000];
int minq[200000];
int maxq[200000];

bool comp(node x, node y)
{
	return x.x < y.x;
}

int main()
{
	n = read();
	d = read();
	rep(i, 1, n)
	{
		x[i].x = read();
		x[i].y = read();
	}
	sort(x + 1, x + n + 1, comp);
	int last = 0;
	rep(i, 1, n)
	{
		if (x[i].x != x[i - 1].x)
		{
			last++;
			T[last] = x[i].x;
			minx[last] = x[i].y;
			maxx[last] = x[i].y;
		}
		else
		{
			minx[last] = min(minx[last], x[i].y);
			maxx[last] = max(maxx[last], x[i].y);
		}
	}
//	rep(i, 1, last)
//	{
//		printf("X%d %d %d\n", i, minx[i], maxx[i]);
//	}
	int tail = 0;
	int headmin = 0;
	int tailmin = -1;
	int headmax = 0;
	int tailmax = -1;
	int ans = INF;
	rep(i, 1, last)
	{
		while (minq[headmin] < i && headmin <= tailmin)
		{
			headmin++;
		}
		while (maxq[headmax] < i && headmax <= tailmax)
		{
			headmax++;
		}
//		printf("%d %d %d %d\n", i, tail, minx[minq[headmin]], maxx[maxq[headmax]]);
		while (maxx[maxq[headmax]] - minx[minq[headmin]] < d && tail < last)
		{
			tail++;
			while (minx[minq[tailmin]] >= minx[tail] && headmin <= tailmin)
			{
				tailmin--;
			}
			tailmin++;
			minq[tailmin] = tail;
			while (maxx[maxq[tailmax]] <= maxx[tail] && headmax <= tailmax)
			{
				tailmax--;
			}
			tailmax++;
			maxq[tailmax] = tail;
//			printf("%d %d %d %d %d %d\n", i, tail, minx[minq[headmin]], minx[minq[tailmin]], maxx[maxq[headmax]], maxx[maxq[tailmax]]);
		}
//		printf("%d %d\n", i, tail);
		if (maxx[maxq[headmax]] - minx[minq[headmin]] >= d)
		{
			ans = min(ans, T[tail] - T[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
