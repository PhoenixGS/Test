#include <cstdio>
#include <cstring>

int n;
int qx, qy;
bool flag[20000];
int edgenum;
bool flagX;
int f[20000];
int vet[20000];
int next[20000];
int head[20000];
int father[20000];
bool visit[20000];
int root;

int findfather(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    return f[x] = findfather(f[x]);
}

void add(int u, int v)
{
    edgenum++;
    vet[edgenum] = v;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

void LCA(int u)
{
    if (flagX)
    {
        return;
    }
    visit[u] = true;
    for (int i = head[u]; i; i = next[i])
    {
        int v = vet[i];
        LCA(v);
        if (flagX)
        {
            return;
        }
        f[v] = u;
        if (visit[qx] && visit[qy])
        {
            int fx = findfather(qx);
            int fy = findfather(qy);
            if (fx == fy)
            {
                printf("%d\n", fx);
                flagX = true;
                return;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        edgenum = 0;
        flagX = false;
        memset(flag, 0, sizeof(flag));
        memset(vet, 0, sizeof(vet));
        memset(next, 0, sizeof(next));
        memset(head, 0, sizeof(head));
        memset(visit, 0, sizeof(visit));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            flag[v] = true;
            add(u, v);
        }
        scanf("%d%d", &qx, &qy);
        for (int i = 1; i <= n; i++)
        {
            if (flag[i] == false)
            {
                root = i;
            }
        }
        LCA(root);
    }
    return 0;
}
