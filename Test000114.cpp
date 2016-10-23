#include <cstdio>
#include <cstring>

int dis[50000];
bool flag[50000];
int head[50000];
int next[100000];
int vet[100000];
int que[20000];
int n, s, t;
int edgenum;

void add(int u, int v)
{
    edgenum++;
    vet[edgenum] = v;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        scanf("%d%d", &s, &t);
        memset(head, 0, sizeof(head));
        edgenum = 0;
        for (int i = 1; i <= n; i++)
        {
            int T_T;
            scanf("%d", &T_T);
            if (i - T_T >= 1)
            {
                add(i, i - T_T);
            }
            if (i + T_T <= n)
            {
                add(i, i + T_T);
            }
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
                if (dis[u] + 1 < dis[v])
                {
                    dis[v] = dis[u] + 1;
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
        if (dis[t] == 1000000000)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", dis[t]);
        }
    }
    return 0;
}
