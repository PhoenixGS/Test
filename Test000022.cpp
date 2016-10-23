#include <cstdio>
#include <algorithm>

using namespace std;

int x[2000];
int f[2000];
int c[2000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &c[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= x[i]; j--)
        {
            f[j] = max(f[j], f[j - x[i]] + c[i]);
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
