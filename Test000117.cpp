#include <cstdio>
#include <cstring>

double f[200][200];
int n, _;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%lf", &f[i][j]);
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i != j && i != k && j != k && f[i][k] * f[k][j] > f[i][j])
                    {
                        f[i][j] = f[i][k] * f[k][j];
                    }
                }
            }
        }
        scanf("%d", &_);
        while (_--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (f[u][v] == 0.0)
            {
                printf("What a pity!\n");
            }
            else
            {
                printf("%.3f\n", f[u][v]);
            }
        }
    }
    return 0;
}
