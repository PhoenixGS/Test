#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long a[4][4];
long long b[4][4];
long long F[4][4] = {2, 1, 1, 0, 
                     1, 2, 0, 1,
                     1, 0, 2, 1,
                     0, 1, 1, 2};
long long tmp[4][4];
long long X[4] = {2, 1, 1, 0};

int main()
{
    int _;
    scanf("%d", &_);
    while (_--)
	{
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = 0;
                }
                tmp[i][j] = F[i][j];
            }
        }
        n--;
        while (n)
        {
            if (n & 1)
            {
                memset(b, 0, sizeof(b));
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            b[i][k] = (b[i][k] + a[i][j] * tmp[j][k]) % 10007;
                        }
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        a[i][j] = b[i][j];
                    }
                }
            }
            memset(b, 0, sizeof(b));
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        b[i][k] = (b[i][k] + tmp[i][j] * tmp[j][k]) % 10007;
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tmp[i][j] = b[i][j];
                }
            }
            n >>= 1;
        }
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans = (ans + a[0][i] * X[i]) % 10007;
        }
        printf("%d\n", ans);
    }
	return 0;
}
