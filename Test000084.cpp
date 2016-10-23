#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long a[2][2];
long long b[2][2];
long long tmp[2][2];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	a[0][0] = 1;
	a[0][1] = 0;
	a[1][0] = 0;
	a[1][1] = 1;
	tmp[0][0] = 1;
	tmp[0][1] = 1;
	tmp[1][0] = 1;
	tmp[1][1] = 0;
	while (n)
	{
		if (n & 1)
		{
			memset(b, 0, sizeof(b));
			for (int i = 0; i <= 1; i++)
			{
				for (int j = 0; j <= 1; j++)
				{
					for (int k = 0; k <= 1; k++)
					{
						b[i][k] = (b[i][k] + a[i][j] * tmp[j][k]) % m;
					}
				}
			}
			for (int i = 0; i <= 1; i++)
			{
				for (int j = 0; j <= 1; j++)
				{
					a[i][j] = b[i][j];
				}
			}
		}
		memset(b, 0, sizeof(b));
		for (int i = 0; i <= 1; i++)
		{
			for (int j = 0; j <= 1; j++)
			{
				for (int k = 0; k <= 1; k++)
				{
					b[i][k] = (b[i][k] + tmp[i][j] * tmp[j][k]) % m;
				}
			}
		}
		for (int i = 0; i <= 1; i++)
		{
			for (int j = 0; j <= 1; j++)
			{
				tmp[i][j] = b[i][j];
			}
		}
		n >>= 1;
	}
	cout << a[1][0] << endl;
	return 0;
}
