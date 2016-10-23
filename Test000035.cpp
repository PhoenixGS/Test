#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int f[2000][2][300];
int s[2000][2][300];

int main()
{
	int n, m, kk;
	scanf("%d%d%d", &n, &m, &kk);
	string st1;
	string st2;
	cin >> st1;
	cin >> st2;
	st1 = '$' + st1;
	st2 = '%' + st2;
	for (int i = 1; i <= n; i++)
	{
		if (st1[i] == st2[1])
		{
			f[i][1][1] = 1;
		}
		s[i][1][1] = (s[i - 1][1][1] + f[i][1][1]) % 1000000007;
	}
	for (int j = 2; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= kk; k++)
			{
				int now = j % 2;
				if (st1[i] != st2[j])
				{
					f[i][now][k] = 0;
					s[i][now][k] = (s[i - 1][now][k] + f[i][now][k]) % 1000000007;
					continue;
				}
				f[i][now][k] = (f[i - 1][1 - now][k] + s[i - 1][1 - now][k - 1]) % 1000000007;
				s[i][now][k] = (s[i - 1][now][k] + f[i][now][k]) % 1000000007;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + f[i][m % 2][kk]) % 1000000007;
	}
	printf("%d\n", ans);
	return 0;
}
