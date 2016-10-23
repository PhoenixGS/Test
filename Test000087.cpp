#include <cstdio>
#include <cstring>

int F[1000][1000];
int X[1000][1000];
int ans[1000][1000];

int main()
{
    int n, times;
    scanf("%d%d", &n, &times);
    for (int i = 0; i < n; i++)
    {
        char st[20];
        scanf("%s", st);
        for (int j = 0; j < n; j++)
        {
            if (st[j] - 48 != 0)
            {
                F[(st[j] - 49) * n + i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            F[j * n + i][(j + 1) * n + i] = 1;
        }
    }
    int N = n * 9;
    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", F[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < N; i++)
    {
        ans[i][i] = 1;
    }
    while (times)
    {
        if (times & 1)
        {
            memset(X, 0, sizeof(X));
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        X[i][k] = (X[i][k] + ans[i][j] * F[j][k]) % 2009;
                    }
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    ans[i][j] = X[i][j];
                }
            }
        }
        memset(X, 0, sizeof(X));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    X[i][k] = (X[i][k] + F[i][j] * F[j][k]) % 2009;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                F[i][j] = X[i][j];
            }
        }
        times >>= 1;
        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }*/
    }
    printf("%d\n", ans[0][n - 1]);
    return 0;
}
