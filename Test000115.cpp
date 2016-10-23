#include <cstdio>
#include <cstring>

int dis[50000];
bool flag[50000];
int head[50000];
int next[100000];
int vet[100000];
int que[30000];
int val[100000];
int F[30000];
int n, m;
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
    while (scanf("%d%d", &n, &m) != EOF)
    {
        edgenum = 0;
        memset(head, 0, sizeof(head));
        memset(F, 0, sizeof(F));
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= n; i++)
        {
            add(0, i, 888);
        }
        bool X_X = false;
        for (int i = 1; i <= m; i++)
        {
            int X, Y;
            scanf("%d%d", &X, &Y);
            add(Y, X, 1);
            if (X == Y)
            {
                X_X = true;
                break;
            }
        }
        if (X_X)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 0;
        }
        int H = 0;
        int T = 0;
        que[H] = 0;
        F[0] = 1;
        flag[0] = true;
        while (H <= T)
        {
            int u = que[H % 20000];
            for (int i = head[u]; i; i = next[i])
            {
                int v = vet[i];
                //printf("^_^%d %d\n", u, val[i]);
                if (dis[u] + val[i] > dis[v])
                {
                    dis[v] = dis[u] + val[i];
                    F[v]++;
                    //printf("*_*%d %d\n", v, flag[v]);
                    if (F[v] > n)
                    {
                        X_X = true;
                        break;
                    }
                    if (! flag[v])
                    {
                        T++;
                        que[T % 20000] = v;
                        flag[v] = true; 
                    }
                }
            }
            if (X_X)
            {
                break;
            }
            flag[u] = false;
            H++;
        }
        if (X_X)
        {
            printf("-1\n");
            continue;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dis[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
