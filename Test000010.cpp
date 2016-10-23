#include <cstdio>
#include <algorithm>

using namespace std;

int x[1000][1000];
int f[1000][1000];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &x[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + x[i][j];
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
