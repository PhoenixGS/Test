#include <cstdio>

int x[5000];
int s[5000];
int f[5000][5000][2];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		s[i] = s[i - 1] + x[i];
	}
	f[1][1][0] = s[1];
	f[2][2][0] = s[2];
	f[2][1][1] = x[1] - x[2];
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= 2 * j; k++)
			{
				f[i + k][k][0] = f[i][j][1] + s[i + k] - s[i];
				f[i + k][k][1] = f[i][j][0] - s[i + k] + s[i];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (f[n][i][0] > ans)
		{
			ans = f[n][i][0];
		}
	}
	printf("%d\n", (s[n] + ans) / 2);
	return 0;
}
