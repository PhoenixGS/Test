#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int f[200000];
int s[200000];

int findf(int x)
{
	if (x == f[x])
	{
		return x;
	}
	return f[x] = findf(f[x]);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		s[i] = 1;
	}
	char st[20];
	while (m--)
	{
		scanf("%s", st);
		if (st[0] == 'M')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			int xx = findf(x);
			int yy = findf(y);
			if (xx != yy)
			{
				f[xx] = yy;
				s[yy] += s[xx];
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			int xx = findf(x);
			printf("%d\n", s[xx]);
		}
	}
	return 0;
}
