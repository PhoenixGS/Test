#include <cstdio>

int f[300];

int main()
{
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 300; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	int x;
	while (scanf("%d", &x) == 1)
	{
		printf("%d\n", f[x]);
	}
	return 0;
}
