#include <cstdio>
#include <cstring>

int k;
int x[1000];
int tmp[1000][1000];
int T[1000][1000];
int F[1000][1000];
int step;

int main()
{
    scanf("%d", &k);
    while (k)
    {
        memset(x, 0, sizeof(x));
        memset(tmp, 0, sizeof(tmp));
        memset(T, 0, sizeof(T));
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &tmp[k - i - 1][k - 1]);
        }
        for (int i = 0; i < k - 1; i++)
        {
            tmp[i + 1][i] = 1;
        }
        for (int i = 0; i < k; i++)
        {
            T[i][i] = 1;
        }
        scanf("%d", &step);
        while (step)
        {
            if (step & 1)
            {
                memset(F, 0, sizeof(F));
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < k; j++)
                    {
                        for (int v = 0; v < k; v++)
                        {
                            F[i][v] = (F[i][v] + T[i][j] * tmp[j][v]) % 10000;
                        }
                    }
                }
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < k; j++)
                    {
                        T[i][j] = F[i][j];
                    }
                }
            }
            memset(F, 0, sizeof(F));
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    for (int v = 0; v < k; v++)
                    {
                        F[i][v] = (F[i][v] + tmp[i][j] * tmp[j][v]) % 10000;
                    }
                }
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    tmp[i][j] = F[i][j];
                }
            }
            step >>= 1;
        }
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans = (ans + x[i] * T[i][0]) % 10000;
        }
        printf("%d\n", ans);
        scanf("%d", &k);
    }
    return 0;
}
