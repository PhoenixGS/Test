#include <cstdio>

int f[100][100];
int n;

void calc(int &x, int &y)
{
	if (x == 1 && y == n)
	{
		x++;
		return;
	}
	int xx = x - 1;
	int yy = y + 1;
	if (xx < 1)
	{
		xx = n;
	}
	if (yy > n)
	{
		yy = 1;
	}
	if (f[xx][yy])
	{
		x = x + 1;
		return;
	}
	x = xx;
	y = yy;
	return;
}

int main()
{
	scanf("%d", &n);
	int x = 1;
	int y = (n + 1) / 2;
	int now = 1;
	f[x][y] = now;
	for (int i = 2; i <= n * n; i++)
	{
		now++;
		calc(x, y);
		f[x][y] = now;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			printf("%d ", f[i][j]);
		}
		printf("%d\n", f[i][n]);
	}
	return 0;
}
