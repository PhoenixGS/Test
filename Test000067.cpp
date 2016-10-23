#include <cstdio>

struct edge
{
	int u, v, c;
};

edge x[200000];

bool comp(edge x, edge y)
{
	return 
}


int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x[i].u, &x[i].v, &x[i].c);
	}
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	sort(x + 1, x + m + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		if (x[i].c == 1 && findf(x[i].u) != findf(x[i].v))
		{
			father[findf(x[i].u)] = findf(x[i].v);
		}
	}
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		if (x[i].c == 0 && findf(x[i].u) != findf(x[i].v))
		{
			father[findf(x[i].u)] = findf(x[i].v);
			flag[i] = true;
			total++;
		}
	}
	if (total > k)
	{
		printf("no solution\n");
		return 0;
	}
	if (total == k)
	{
		for (int i = 1; i <= m; i++)
		{
			if (flag[i])
			{
				printf("%d %d %d\n", )
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		if (flag[i] == true)
		{
			
		}
	}
}
