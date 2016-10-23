#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int x[200000];
int f[2][4][4][4][4];
int n;
int ans;

int calc(int x, int y, int z)
{
	if (y == 0)
	{
		return  1;
	}
	if (x == 0)
	{
		if (y != z)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	if (x != y && x != z && y != z)
	{
		return 3;
	}
	if (x != y || x != z || y != z)
	{
		return 2;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	string st;
	cin >> st;
	for (int i = 0; i < st.length(); i++)
	{
		if (st[i] == 'M')
		{
			x[i + 1] = 1;
		}
		if (st[i] == 'B')
		{
			x[i + 1] = 2;
		}
		if (st[i] == 'F')
		{
			x[i + 1] = 3;
		}
	}
	memset(f, -1, sizeof(f));
	f[0][0][0][0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		int thisx = i % 2;
		int nextx = 1 - i % 2;
		for (int A = 0; A <= 3; A++)
		{
			for (int B = 0; B <= 3; B++)
			{
				for (int C = 0; C <= 3; C++)
				{
					for (int D = 0; D <= 3; D++)
					{
						if ((B == 0 && A != 0) || (D == 0 && C != 0))
						{
							continue;
						}
						if (f[thisx][A][B][C][D] != -1)
						{
							int now = x[i + 1];
							f[nextx][B][now][C][D] = max(f[nextx][B][now][C][D], f[thisx][A][B][C][D] + calc(A, B, now));
							f[nextx][A][B][D][now] = max(f[nextx][A][B][D][now], f[thisx][A][B][C][D] + calc(C, D, now));
							if (i == n - 1)
							{
								ans = max(ans, max(f[nextx][B][now][C][D], f[nextx][A][B][D][now]));
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
