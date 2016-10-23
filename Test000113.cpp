#include <cstdio>
#include <cstring>

int dis[50000];
bool flag[50000];
int head[50000];
int next[100000];
int vet[100000];
int val[100000];
int que[20000];
int n, m, s, t;
int edgenum;

void add(int u, int v, int cost)
{
    edgenum++;
    vet[edgenum] = v;
    val[edgenum] = cost;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

int main()
{
    while (true)
    {
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(head));
        if (n == 0 && m == 0)
        {
            break;
        }
        edgenum = 0;
        s = 1;
        t = n;
        for (int i = 0; i < m; i++)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            add(u, v, cost);
            add(v, u, cost);
        }
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 1000000000;
        }
        dis[s] = 0;
        int H = 0;
        int T = 0;
        que[H] = s;
        while (H <= T)
        {
            int u = que[H % 10000];
            for (int i = head[u]; i; i = next[i])
            {
                int v = vet[i];
                if (dis[u] + val[i] < dis[v])
                {
                    dis[v] = dis[u] + val[i];
                    if (! flag[v])
                    {
                        T++;
                        que[T % 10000] = v;
                        flag[v] = true; 
                    }
                }
            }
            flag[u] = false;
            H++;
        }
        printf("%d\n", dis[t]);
    }
    return 0;
}
