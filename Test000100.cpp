#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

double t[20][20][20][20][20];
int s[20][20];
int x[20][20];
int n, m, k;
double T;
bool flag[20][20][20][20][20];

double dfs(int x1, int y1, int x2, int y2, int K)
{
	if (flag[x1][y1][x2][y2][K])
	{
		return t[x1][y1][x2][y2][K];
	}
	flag[x1][y1][x2][y2][K] = true;
	double ans;
	if (K == 0)
	{
		ans = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
		ans = (ans - T) * (ans - T);
//		printf("X%d %d %d %d %d %f\n", x1, y1, x2, y2, K, ans);
		return t[x1][y1][x2][y2][K] = ans;
	}
	ans = 1000000000.0;
	for (int i = x1; i < x2; i++)
	{
		for (int j = 0; j < K; j++)
		{
			ans = min(ans, dfs(x1, y1, i, y2, j) + dfs(i + 1, y1, x2, y2, K - j - 1));
		}
	}
	for (int i = y1; i < y2; i++)
	{
		for (int j = 0; j < K; j++)
		{
			ans = min(ans, dfs(x1, y1, x2, i, j) + dfs(x1, i + 1, x2, y2, K - j - 1));
		}
	}
//	printf("%d %d %d %d %d %f\n", x1, y1, x2, y2, K, ans);
	return t[x1][y1][x2][y2][K] = ans;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &x[i][j]);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x[i][j];
		}
	}
	T = (double)s[n][m] / k;
	printf("%.2f\n", sqrt(dfs(1, 1, n, m, k - 1) / k));
//	printf("%f\n", T);
//	printf("%d\n", s[n][m]);
//	printf("%d\n", k);
	return 0;
}
