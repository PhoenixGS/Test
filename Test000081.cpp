#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int ans;
int Map[20][20];
int tmp[20][20];
int n;
int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};
int x[20];

int check()
{
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			tmp[i][j] = Map[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (x[i])
		{
			for (int k = 0; k < 5; k++)
			{
				int xx = 1 + dx[k];
				int yy = i + dy[k];
				if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
				{
					tmp[xx][yy] = tmp[xx][yy] ^ 1;
				}
			}
			total++;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tmp[i - 1][j])
			{
				for (int k = 0; k < 5; k++)
				{
					int xx = i + dx[k];
					int yy = j + dy[k];
					if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
					{
						tmp[xx][yy] = tmp[xx][yy] ^ 1;
					}
				}
				total++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tmp[i][j])
			{
				return 1000000000;
			}
		}
	}
	return total;
}

void dfs(int t)
{
	if (t > n)
	{
		int ttmp = check();
		if (ttmp < ans)
		{
			ans = ttmp;
		}
		return;
	}
	x[t] = 0;
	dfs(t + 1);
	x[t] = 1;
	dfs(t + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			string st;
			cin >> st;
			for (int j = 1; j <= n; j++)
			{
				if (st[j - 1] == 'w')
				{
					Map[i][j] = 1;
				}
				else
				{
					Map[i][j] = 0;
				}
			}
		}
		ans = 1000000000;
		dfs(1);
		if (ans == 1000000000)
		{
			printf("inf\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
