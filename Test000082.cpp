#include <cstdio>
#include <iostream>

using namespace std;

int f[100][100];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &f[i][n + 1]);
		}
		for (int i = 1; i <= n; i++)
		{
			int A;
			scanf("%d", &A);
			f[i][n + 1] = f[i][n + 1] ^ A;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				f[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			f[i][i] = 1;
		}
		while (true)
		{
			int A, B;
			scanf("%d%d", &A, &B);
			if (A == 0 && B == 0)
			{
				break;
			}
			f[B][A] = 1;
		}
		int now = 1;
		for (int i = 1; i <= n; i++)
		{
			int j;
			for (j = now; j <= n; j++)
			{
				if (f[j][i])
				{
					break;
				}
			}
			if (j == n + 1)
			{
				continue;
			}
			for (int k = i; k <= n + 1; k++)
			{
				swap(f[j][k], f[now][k]);
			}
			for (int j = now + 1; j <= n; j++)
			{
				if (f[j][i])
				{
					for (int k = 1; k <= n + 1; k++)
					{
						f[j][k] = f[j][k] ^ f[now][k];
					}
				}
			}
			now++;
		}
		int FLAG = true;
		for (int i = now; i <= n; i++)
		{
			if (f[i][n + 1] == 1)
			{
				FLAG = false;
			}
		}
		if (! FLAG)
		{
			printf("Oh,it's impossible~!!\n");
		}
		else
		{
			int ans = 1;
			for (int i = now; i <= n; i++)
			{
				ans *= 2;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
