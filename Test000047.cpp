#include <cstdio>
#include <algorithm>

using namespace std;

struct text
{
	int u, v, len;
};

text x[20000];
int f[10000];

bool comp(text x, text y)
{
	return x.len < y.len;
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
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x[i].u, &x[i].v, &x[i].len);
	}
	sort(x + 1, x + m + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int u = x[i].u;
		int v = x[i].v;
		int len = x[i].len;
		int x = findfather(u);
		int y = findfather(v);
		if (x != y)
		{
			ans = len;
			f[x] = y;
		}
	}
	printf("%d\n", ans);
	return 0;
}
