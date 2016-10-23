#include <cstdio>

int f[2000][2000];
int _;
int n, m;

int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        f[1][i] = f[i][1] = 1;
    }
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 2; j <= 1000; j++)
        {
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 100000007;
        }
    }
    scanf("%d", &_);
    while (_--)
    {
        scanf("%d%d", &m, &n);
        printf("%d\n", f[n + 1][m - n + 1]);
    }
    return 0;
}
