#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, h, s;
int c[200];
int w[200];
int f[200][200];

int main()
{
    int _;
    scanf("%d", &_);
	while (_--)
	{
        int n, m;
		for (int i = 1; i <= h; i++)
		{
			scanf("%d%d", &c[i], &w[i]);
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= s; j++)
			{
				for (int k = w[i]; k <= m; k++)
				{
					f[j][k] = max(f[j][k], )
				}
			}
		}
		if (f[s][m] >= n)
		{
			for (int i = 0; i <= m; i++)
			{
				if (f[s][i] >= n)
				{
					printf("%d\n", m - i);
					break;
				}
			}
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
