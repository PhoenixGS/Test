#include <cstdio>
#include <algorithm>

using namespace std;

int x[1005][1005];
int s[1005][1005];
int money[1005];
int f[1005][1005];
int F[1005];
int n, m, p;
int head[1005];
int tail[1005];
int q[1005][1005];

int now(int x)
{
	return ((x - 1) % n + n) % n + 1;
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
	for (int i = 1; i <= n; i++)
	{
		head[i] = 1;
		tail[i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		F[i] = -1000000000;
		for (int j = 1; j <= n; j++)
		{
			int loc = now(i - j);
			while (head[loc] <= tail[loc] && q[loc][head[loc]] < i - min(i, p))
			{
				head[loc]++;
			}
			while (head[loc] <= tail[loc] && g(i - 1, now(j - 1)) >= g(q[loc][tail[loc]], now(q[loc][tail[loc]] - loc)))
			{
				tail[loc]--;
			}
			tail[loc]++;
			q[loc][tail[loc]] = i - 1;
			int tmpx = q[loc][head[loc]];
			int tmpy = now(tmpx - loc);
			f[i][j] = max(f[i][j], F[tmpx] + s[i][j] - s[tmpx][now(tmpy)] - money[now(tmpy)]);
			F[i] = max(F[i], f[i][j]);
		}
	}
	printf("%d\n", F[m]);
	return 0;
}
