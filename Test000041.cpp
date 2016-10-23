#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char sss[300000];
long long s[300000];
long long b[300000];
long long pp = 1637281495;

long long mo(long long a)
{
	if (a >= 0 && a < pp)
	{
		return a;
	}
	a %= pp;
	if (a < 0)
	{
		a += pp;
	}
	return a;
}

long long find(int l, int r)
{
	return mo(s[r] - s[l - 1] * b[r - l + 1]);
}

int main()
{
	scanf("%s", sss + 1);
	int n = strlen(sss + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i] = (s[i - 1] * 31 + sss[i]) % 1637281495;
	}
	b[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		b[i] = (b[i - 1] * 31) % 1637281495;
	}
	for (int i = 1; i <= n; i++)
	{
		if (n % i != 0)
		{
			continue;
		}
		if (find(1, i) == find(n - i + 1, n) && find(1, n - i) == find(i + 1, n))
		{
			printf("%d\n", n / i);
			return 0;
		}
	}
	return 0;
}
