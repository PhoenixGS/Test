#include <cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n % (m - 1) == 0)
    {
        printf("%d\n", n / (m - 1) * m);
    }
    else
    {
        printf("%d\n", n / (m - 1) * m + n % (m - 1) + 1);
    }
    return 0;
}
