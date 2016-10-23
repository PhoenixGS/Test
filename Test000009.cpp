#include <cstdio>

int x[200000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (x[i] % 10 != x[i - 1] % 10)
		{
			ans++;
		}
	}
	ans++;
	printf("%d\n", ans);
	return 0;
}
