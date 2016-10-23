#include <cstdio>

int ll, m, n;
int x[60000];

int check(int t)
{
	int total = 0;
	int tmp = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		if (x[i] - tmp < t)
		{
			total++;
		}
		else
		{
			tmp = x[i];
		}
	}
	if (total > m) return false;
	return true;
}

int main()
{
	scanf("%d%d%d", &ll, &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	x[n + 1] = ll;
	int l = 0;
	int r = ll;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
