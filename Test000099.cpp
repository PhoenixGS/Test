#include <cstdio>
#include <algorithm>

using namespace std;

int a[2000][2000];
int rec1[2000][2000];
int rec2[2000][2000];
int tt[2000];
int q[2000];
int b[2000];
int n, m, k;

void work(int *b, int n, int z)
{
    int t = 1;
    int w = 0;
    for (int i = 1; i <= n; i++)
    {
        while (t <= w && b[q[w]] * z >= b[i] * z)
        {
            w--;
        }
        w++;
        q[w] = i;
        while (t <= w && q[t] <= i - k)
        {
            t++;
        }
        tt[i] = b[q[t]];
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i][j];
        }
        work(b, n, 1);
        for (int i = 1; i <= n; i++)
        {
            rec1[i][j] = tt[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[j] = rec1[i][j];
        }
        work(b, m, 1);
        for (int j = 1; j <= m; j++)
        {
            rec1[i][j] = tt[j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i][j];
        }
        work(b, n, -1);
        for (int i = 1; i <= n; i++)
        {
            rec2[i][j] = tt[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[j] = rec2[i][j];
        }
        work(b, m, -1);
        for (int j = 1; j <= m; j++)
        {
            rec2[i][j] = tt[j];
        }
    }
    int ans = 1000000000;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            ans = min(ans, rec2[i][j] - rec1[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
