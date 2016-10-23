#include <cstdio>
#include <algorithm>

using namespace std;

int x[400000];
int f[400000];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1000000000;
    }
    int ansl = 0;
    for (int i = 1; i < k; i++)
    {
        if (x[i] >= x[k])
        {
            continue;
        }
        int tmp = lower_bound(f + 1, f + n + 1, x[i]) - f;
        f[tmp] = x[i];
        ansl = max(ansl, tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1000000000;
    }
    int ansr = 0;
    for (int i = k + 1; i <= n; i++)
    {
        if (x[i] <= x[k])
        {
            continue;
        }
        int tmp = lower_bound(f + 1, f + n + 1, x[i]) - f;
        f[tmp] = x[i];
        ansr = max(ansr, tmp);
    }
    printf("%d\n", ansl + 1 + ansr);
    return 0;
}
