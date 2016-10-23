#include <cstdio>
#include <algorithm>

using namespace std;

long long x[2000][2000];
long long f[2000][2000];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        x[i][0] = 1000000000;
    }
    for (int i = 0; i <= m; i++)
    {
        x[0][i] = 1000000000;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &x[i][j]);
            f[i][j] = 1000000000;
        }
    }
    f[1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i + j) & 1)
            {
                if (i > 1)
                {
                    f[i][j] = min(f[i][j], f[i - 1][j] + x[i - 1][j] * x[i][j]);
                }
                if (j > 1)
                {
                    f[i][j] = min(f[i][j], f[i][j - 1] + x[i][j] * x[i][j - 1]);
                }
                if (i + 1 <= n) 
                {
                    f[i + 1][j] = min(f[i + 1][j], f[i][j]);
                }
                if (j + 1 <= m)
                {
                    f[i][j + 1] = min(f[i][j + 1], f[i][j]);
                }
            }
        }
    }
    printf("%lld\n", f[n][m]);
    return 0;
}
