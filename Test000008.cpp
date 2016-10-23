#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int f[30000];
int d[30000];
int in[30000];
int fi[30000];
int sum[30000];

int findf(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	int fx = f[x];
	f[x] = findf(f[x]);
	d[x] = d[x] ^ d[fx];
	return f[x];
}

int main()
{
	int n, Q;
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		d[i] = 0;
	}
	int T = 0;
	while (Q--)
	{
		char st[200];
		scanf("%s", st);
		if (st[0] == 'I')
		{
			T++;
			char s[1000];
			gets(s);
			int x, y, z;
			int t = sscanf(s, "%d%d%d", &x, &y, &z);
			if (t == 2)
			{
				x++;
				int fx = findf(x);
				if (fx == 0)
				{
					if (d[x] != y)
					{
						printf("The first %d facts are conflicting.\n", T);
						return 0;
					}
				}
				else
				{
					f[fx] = 0;
					d[fx] = d[x] ^ y;
				}
			}
			else
			{
				x++, y++;
				int fx = findf(x), fy = findf(y);
				if (fx == fy)
				{
					if ((d[x] ^ d[y]) != z)
					{
						printf("The first %d facts are conflicting.\n", T);
						return 0;
					}
				}
				else
				{
					if (fx == 0)
					{
						f[fy] = fx;
						d[fy] = d[x] ^ d[y] ^ z;
					}
					if (fy == 0)
					{
						f[fx] = fy;
						d[fx] = d[x] ^ d[y] ^ z;
					}
					if (fx != 0 && fy != 0)
					{
						f[fx] = fy;
						d[fx] = d[x] ^ d[y] ^ z;
					}
				}
				//printf("%d %d %d %d\n", fx, fy, f[fx], d[fx]);
			}
		}
		else
		{
			int k;
			scanf("%d", &k);
			for (int i = 1; i <= k; i++)
			{
				scanf("%d", &in[i]);
				in[i]++;
				//printf("%d %d ", in[i], f[in[i]]);
				fi[i] = findf(in[i]);
				//printf("%d\n", fi[i]);
				sum[fi[i]]++;
			}
			bool flag = true;
			for (int i = 1; i <= k; i++)
			{
				if ((fi[i] != 0) && (sum[fi[i]] & 1))
				{
					//printf("%d\n", sum[fi[i]]);
					flag = false;
				}
			}
			for (int i = 1; i <= k; i++)
			{
				sum[fi[i]]--;
			}
			if (flag == false)
			{
				printf("I don't know.\n");
				continue;
			}
			int ans = 0;
			for (int i = 1; i <= k; i++)
			{
				ans ^= d[in[i]];
			}
			printf("%d\n", ans);
		}
	}
}
