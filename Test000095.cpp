#include <cstdio>
#include <algorithm>

using namespace std;

int vet[1000];
int next[1000];
int head[1000];
int f[1000][1000];
int c[1000];
int n, m;
int edgenum = 0;

void add(int u, int v)
{
    edgenum++;
    vet[edgenum] = v;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

void dfs(int u)
{
    for (int i = m; i >= 1; i--)
    {
        f[u][i] = f[u][i - 1] + c[u];
    }
    f[u][0] = -1000000000;
    for (int i = head[u]; i; i = next[i])
    {
        for (int j = 0; j <= m; j++)
        {
            f[vet[i]][j] = f[u][j];
        }
        dfs(vet[i]);
        for (int j = 0; j <= m; j++)
        {
            f[u][j] = max(f[u][j], f[vet[i]][j]);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    while (n || m)
    {
        edgenum = 0;
        for (int i = 0; i <= n; i++)
        {
            head[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            add(x, i);
            scanf("%d", &c[i]);
        }
        m++;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = 0;
            }
        }
        dfs(0);
        int ans = 0;
        for (int i = 0; i <= m; i++)
        {
            ans = max(ans, f[0][i]);
        }
        printf("%d\n", ans);
        scanf("%d%d", &n, &m);
    }
    return 0;
}
