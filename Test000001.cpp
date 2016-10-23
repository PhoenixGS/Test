#include <cstdio>

int n, m;
int edgenum;
bool F;
int vet[300000];
int next[300000];
int head[50000];
int flag[50000];
int xx[200000];
int yy[200000];
int zz[200000];

void add(int uu, int vv)
{
    edgenum++;
    vet[edgenum] = vv;
    next[edgenum] = head[uu];
    head[uu] = edgenum;
}

void dfs(int k)
{
    for (int i = head[k]; i; i = next[i])
    {
        int U = vet[i];
        if (flag[U] == -1)
        {
            flag[U] = 1 - flag[k];
            dfs(U);
        }
        else
        {
            if (flag[U] == flag[k])
            {
                F = true;
                return;
            }
        }
    }
}

bool check(int t)
{
    edgenum = 0;
    for (int i = 1; i <= n; i++)
    {
        head[i] = 0;
        flag[i] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (zz[i] > t)
        {
            add(xx[i], yy[i]);
            add(yy[i], xx[i]);
        }
    }
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == -1)
        {
            flag[i] = 0;
            F = false;
            dfs(i);
            ans = F || ans;
        }
    }
    return ! ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &xx[i], &yy[i], &zz[i]);
    }
    int l = 0;
    int r = 1000000000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
    return 0;
}
