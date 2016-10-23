#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int x[200][200];
int f[200];

int main()
{
    scanf("%d%d", &n, &m);
    while (n || m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &x[i][j]);
            }
        }
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            for (int k = m; k >= 1; k--)
            {
                for (int j = 1; j <= k; j++)
                {
                    f[k] = max(f[k], f[k - j] + x[i][j]);
                }
            }
        }
        printf("%d\n", f[m]);
        scanf("%d%d", &n, &m);
    }
    return 0;
}
