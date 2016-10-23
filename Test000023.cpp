#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int x[100][100];
int f[100][100];

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
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= m; j++)
		{
			f[j][j] = f[j - 1][j - 1] + x[i][j] * (1 << j);
			f[j][0] = f[j - 1][0] + x[i][m - j + 1] * (1 << j);
			for (int k = 1; k < j; k++)
			{
				int left = f[j - 1][k - 1] + x[i][k] * (1 << j);
				int right = f[j - 1][k] + x[i][m - (j - k) + 1] * (1 << j);
				f[j][k] = max(left, right);
			}
		}
		int tmp = 0;
		for (int j = 1; j <= m; j++)
		{
			tmp = max(tmp, f[m][j]);
		}
		ans += tmp;
	}
	printf("%d\n", ans);
}
