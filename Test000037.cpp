#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long f[10005][1005];
long long x[10005];
int head[2];
int tail[2];
long long que[2][10005];

long long calc(int j, int i, int t)
{
	return f[j][t - 1] + (x[i] - x[j + 1]) * (x[i] - x[j + 1]);
}

long long up(int j, int k, int t)
{
	return f[j][t] - f[k][t] + x[j + 1] * x[j + 1] - x[k + 1] * x[k + 1];
}

long long down(int j, int k, int t)
{
	return 2 * (x[j + 1] - x[k + 1]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x + 1, x + n + 1);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	head[0] = 0;
	tail[0] = 0;
	que[0][0] = 0;
	for (int t = 1; t <= m; t++)
	{
		int now = t & 1;
		int pre = 1 - now;
		head[now] = 0;
		tail[now] = 0;
		que[now][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			while (head[pre] + 1 <= tail[pre] && calc(que[pre][head[pre]], i, t) >= calc(que[pre][head[pre] + 1], i, t))
			{
				head[pre]++;
			}
			f[i][t] = calc(que[pre][head[pre]], i, t);
			while (head[now] + 1 <= tail[now] && up(que[now][tail[now] - 1], que[now][tail[now]], t) * down(que[now][tail[now]], i, t) >= up(que[now][tail[now]], i, t) * down(que[now][tail[now] - 1], que[now][tail[now]], t))
			{
				tail[now]--;
			}
			tail[now]++;
			que[now][tail[now]] = i;
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
