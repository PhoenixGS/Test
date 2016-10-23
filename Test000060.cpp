#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool flag[10000000];
int f[10000000];

int main()
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int ans;
	ans = 0;
	if (x > y)
	{
		swap(x, y);
	}
	flag[0] = true;
	for (int i = 0; i < x; i++)
	{
		f[i] = 0;
	}
	flag[x] = true;
	for (int i = x; i < y; i++)
	{
		f[i] = x;
	}
	for (int i = y; i <= n; i++)
	{
		flag[i] = flag[i - x] || flag[i - y];
		if (flag[i])
		{
			f[i] = i;
			ans = i;
		}
		else
		{
			f[i] = f[i - 1];
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (flag[i])
		{
			int tmp = i / 2;
			tmp = i - tmp;
			if (tmp + f[n - tmp] > ans)
			{
				ans = tmp + f[n - tmp];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
