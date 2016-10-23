#include <cstdio>
#include <algorithm>

using namespace std;

int x[2000][2000];
int s[2000][2000];
int money[2000];
int f[2000][2000];
int F[2000];
int n, m, p;
int head[5000];
int tail[5000];
int q[4005][4005];

int now(int x)
{
    return (x + n - 1) % n + 1;
}

int g(int i, int j)
{
	return F[i] - s[i][j] - money[j];
}

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &x[j][i]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			s[i][j] = s[i - 1][now(j - 1)] + x[i][now(j - 1)];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &money[i]);
	}
	for (int i = -n; i <= m - 1; i++)
	{
		head[i + n] = 1;
		tail[i + n] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		F[i] = -1000000000;
		for (int j = 1; j <= n; j++)
		{
			int loc = i - j;
			while (head[loc + n] <= tail[loc + n] && q[loc + n][head[loc + n]] < i - min(i, p))
			{
				head[loc + n]++;
			}
			while (head[loc + n] <= tail[loc + n] && g(i - 1, now(j - 1)) >= g(q[loc + n][tail[loc + n]], now(q[loc + n][tail[loc + n]] - loc + n)))
			{
				tail[loc + n]--;
			}
			tail[loc + n]++;
			q[loc + n][tail[loc + n]] = i - 1;
			f[i][j] = s[i][j] + g(q[loc + n][head[loc + n]], now(q[loc + n][head[loc + n]] - loc + n));
			printf("%d %d %d\n", i, j, f[i][j]);
			F[i] = max(F[i], f[i][j]);
		}
	}
	printf("%d\n", F[m]);
	return 0;
}
