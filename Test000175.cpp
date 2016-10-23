#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, n, a) for (int i = n; i >= a; i--)
#define Rep(i, u) for (int i = head[u]; i; i = next[i])

struct node
{
	int u, v, cost;
};

int n, m;
node x[2000000];
int f[200000];

bool comp(node x, node y)
{
	return x.cost < y.cost;
}

int findfather(int x)
{
	if (x == f[x])
	{
		return x;
	}
	return f[x] = findfather(f[x]);
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		scanf("%d%d%d", &x[i].u, &x[i].v, &x[i].cost);
	}
	sort(x + 1, x + m + 1, comp);
	rep(i, 1, n)
	{
		f[i] = i;
	}
	int ans = 0;
	rep(i, 1, m)
	{
		int xx = findfather(x[i].u);
		int yy = findfather(x[i].v);
		if (xx != yy)
		{
			f[xx] = yy;
			ans += x[i].cost;
		}
	}
	cout << ans << endl;
	return 0;
}

