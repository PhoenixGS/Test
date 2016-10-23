#include <cstdio>

long long f[20000];

int main()
{
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        printf("%.20f\n", (double)f[i] / (double)f[i - 1]);
    }
    return 0;
}
