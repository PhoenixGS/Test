#include <cstdio>

long long f[1000][1000];
long long s[1000][1000];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    f[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = (f[i][j] + s[i - 1][j - 1]) % 1000000007;
            s[i][j] = (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + f[i][j]) % 1000000007;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%lld ", f[i][j]);
        }
        printf("\n");
    }
    //printf("%lld\n", f[n][m] % 1000000007);
    return 0;
}
