#include <cstdio>

int f[200];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        f[x] = true;
    }
    while (true)
    {
        int flag = true;
        for (int i = 1; i <= 99; i++)
        {
            for (int j = i + 1; j <= 100; j++)
            {
                if (i != j && f[i] && f[j] && ! f[j / i])
                {
                    flag = false;
                    f[j / i] = true;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (f[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
