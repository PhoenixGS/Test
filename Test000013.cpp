#include <cstdio>
#include <iostream>

using namespace std;

long long x[60000];
long long y[60000];
long long xx[60000];
long long yy[60000];
long long f[60000];

int min(long long x, long long y)
{
	if (x > y)
	{
		return y;
	}
	return x;
}

void qsort(int l, int r)
{
	long long midx = x[(l + r) / 2];
	long long midy = y[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (x[i] < midx || x[i] == midx && y[i] < midy)
		{
			i++;
		}
		while (x[j] > midx || x[j] == midx && y[j] > midy)
		{
			j--;
		}
		if (i <= j)
		{
			long long t;
			t = x[i];
			x[i] = x[j];
			x[j] = t;
			t = y[i];
			y[i] = y[j];
			y[j] = t;
			i++;
			j--;
		}
	}
	if (l < j)
	{
		qsort(l, j);
	}
	if (i < r)
	{
		qsort(i, r);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &x[i], &y[i]);
	}
	qsort(1, n);
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		while (num > 0 && xx[num] <= x[i] && yy[num] <= y[i])
		{
			num--;
		}
		num++;
		xx[num] = x[i];
		yy[num] = y[i];
	}
	for (int i = 1; i <= num; i++)
	{
		f[i] = 5000000000000;
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			f[i] = min(f[i], f[j] + xx[i] * yy[j + 1]);
		}
	}
	printf("%lld\n", f[num]);
	return 0;
}
