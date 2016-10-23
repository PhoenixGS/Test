#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int w[20000];
double c[20000];
double f[20000];

int main()
{
    scanf("%d%d", &n, &m);
    while (n || m)
    {
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%lf", &w[i], &c[i]);
            c[i] = 1 - c[i];
        }
        for (int i = 0; i <= n; i++)
        {
            f[i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= w[i]; j--)
            {
                f[j] = min(f[j], f[j - w[i]] * c[i]);
            }
        }
        printf("%.1f%%\n", (1 - f[n]) * 100);
        scanf("%d%d", &n, &m);
    }
    return 0;
}
