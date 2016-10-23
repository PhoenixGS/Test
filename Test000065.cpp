#include <cstdio>
#include <algorithm>

using namespace std;

int x[2000][2000];
int s[2000][2000];
int money[2000];
int f[2000][2000];
int F[2000];
int n, m, p;

int now(int x)
{
    return (x + n - 1) % n + 1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x[j][i]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            s[i][j] = s[i - 1][now(j - 1)] + x[i][now(j - 1)];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &money[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        F[i] = -1000000000;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = -1000000000;
            for (int k = 1; k <= min(i, p); k++)
            {
                f[i][j] = max(f[i][j], F[i - k] + s[i][j] - s[i - k][now(j - k)] - money[now(j - k)]);
            }
            F[i] = max(F[i], f[i][j]);
            printf("%d %d %d\n", i, j, f[i][j]);
        }
    }
    printf("%d\n", F[m]);
    return 0;
}
