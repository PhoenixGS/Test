#include <cstdio>
#include <iostream>

using namespace std;

int n, p, k, m, num;
int s[2000];
int lab[2000];

struct matr
{
	int s[300][300];
	
}g, ans;

matr operator * (matr &a, matr &b)
{
	matr c;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			c.s[i][j] = 0;
			for (int k = 1; k <= num; k++)
			{
				c.s[i][j] = (c.s[i][j] + a.s[i][k] * b.s[k][j]) % 30031;
			}
		}
	}
	return c;
}

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	m = 1 << p;
	for (int i = 1; i < m; i++)
	{
		s[i] = s[i - (i & (-i))] + 1;
	}
	for (int i = 1; i < m; i++)
	{
		if (s[i] == k)
		{
			lab[i] = ++num;
		}
	}
	for (int i = 1; i < m; i++)
	{
		if (s[i] == k)
		{
			if (i & 1)
			{
				int v = i / 2 + (1 << (p - 1));
				g.s[lab[i]][lab[v]]++;
			}
			else
			{
				for (int j = 0; j < p; j++)
				{
					if (i & (1 << j))
					{
						int v = (i - (1 << j)) / 2 + (1 << (p - 1));
						g.s[lab[i]][lab[v]]++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= num; i++)
	{
		ans.s[i][i] = 1;
	}
	n -= k;
	while (n)
	{
		if (n & 1)
		{
			ans = ans * g;
		}
		g = g * g;
		n >>= 1;
	}
	int t = (1 << p) - (1 << (p - k));
	cout << ans.s[lab[t]][lab[t]] << endl;
	return 0;
}
