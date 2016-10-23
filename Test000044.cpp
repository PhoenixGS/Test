#include <cstdio>
#include <cstring>

int maxx[2000000];
int x[2000000];
int s[2000000];
int d[2000000];
int ss[2000000];
int t[2000000];
int tmpx[2000000];
int tmps[2000000];
int n, m;

bool check(int T)
{
	memset(tmpx, 0, sizeof(tmpx));
	memset(tmps, 0, sizeof(tmps));
	for (int i = 1; i <= T; i++)
	{
		tmpx[ss[i]] += d[i];
		tmpx[t[i] + 1] -= d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		tmps[i] = tmps[i - 1] + tmpx[i];
		if (tmps[i] > maxx[i])
		{
			return false;
		}
	}
	/*
	printf("%d:\n", T);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", tmps[i]);
	}
	printf("\n");
	*/
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &maxx[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &d[i], &ss[i], &t[i]);
		x[ss[i]] += d[i];
		x[t[i] + 1] -= d[i];
	}
	int flag = true;
	for (int i = 1; i <= n + 1; i++)
	{
		s[i] = s[i - 1] + x[i];
		if (s[i] > maxx[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		printf("0\n");
		return 0;
	}
	int l = 0;
	int r = m;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("-1\n");
	printf("%d\n", l + 1);
	return 0;
}
