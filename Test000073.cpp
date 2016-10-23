#include <cstdio>
#include <algorithm>

using namespace std;

int a[400000];
int b[400000];
int t[20][400000];
int f[20][400000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= m; j++)
    {
        scanf("%d", &b[j]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                t[i][j] = 1;
                t[i + n][j] = 1;
                t[i][j + m] = 1;
                t[i + n][j + m] = 1;
            }
        }
    }
    int i = 1;
    for (int j = 1; j <= 2 * m; j++)
    {
        if (t[i][j] == t[i][j - 1])
        {
            f[i][j] = f[i][j - 1];
        }
        else
        {
            f[i][j] = f[i][j - 1] + 1;
        }
    }
    int q;
    scanf("%d", &q);
    for (int cas = 1; cas <= q; cas++)
    {
        int sx, sy, tx, ty;
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        if (sy < ty)
        {
            printf("%d\n", min(f[i][ty] - f[i][sy], f[i][sy + m] - f[i][ty]));
        }
        else
        {
            printf("%d\n", min(f[i][sy] - f[i][ty], f[i][ty + m] - f[i][sy]));
        }
    }
    return 0;
}
