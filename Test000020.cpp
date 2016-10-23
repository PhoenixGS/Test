#include <cstdio>
#include <algorithm>

using namespace std;

int x[10000];
int f[10000][10000];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++)
	{
		f[i][1] = (x[1] - x[i]) * (x[1] - x[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			f[i][j] = 1000000000;
			for (int k = j - 1; k <= i - 1; k++)
			{
				f[i][j] = min(f[i][j], f[k][j - 1] + (x[i] - x[k + 1]) * (x[i] - x[k + 1]));
			}
		}
	}
	printf("%d\n", f[n][m]);
}
