#include <cstdio>

long long ans[2000000];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            ans[i * j] += i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
