#include <cstdio>

bool flag[1000];
int min[1000];
int F[1000][1000];

int main()
{
	int n;
	scanf("%d", &n);
	min[0] = 0;
	min[n + 1] = 1000000000;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &F[0][i]);
		min[i] = 1000000000;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &F[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int u = n + 1;
		for (int j = 0; j <= n; j++)
		{
			if (flag[j] == 0 && min[j] < min[u])
			{
				u = j;
			}
		}
		ans += min[u];
		flag[u] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (F[u][j]< min[j])
			{
				min[j] = F[u][j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
