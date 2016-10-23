#include <cstdio>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x[i].u, &x[i].v, &x[i].len);
	}
	sort(x, x + m, comp);
	for (int i = 0; i < m; i++)
	{
		int u = x[i].u;
		int v = x[i].v;
		int xx = findf(u);
		int yy = findf(v);
		if (xx != yy)
		{
			f[xx] = yy;
		}
	}
}
