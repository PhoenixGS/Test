#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dis[50000];
bool flag[50000];
int head[50000];
int next[100000];
int vet[100000];
int val[100000];
int que[20000];
int T, S, D;
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
    while (scanf("%d%d%d", &T, &S, &D) != EOF)
    {
        edgenum = 0;
        memset(head, 0, sizeof(head));
        for (int i = 0; i < T; i++)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            add(u, v, cost);
            add(v, u, cost);
        }
        for (int i = 1; i <= S; i++)
        {
            int T_T;
            scanf("%d", &T_T);
            add(0, T_T, 0);
        }
        for (int i = 1; i <= 1000; i++)
        {
            dis[i] = 1000000000;
        }
        dis[0] = 0;
        int H = 0;
        int T = 0;
        que[H] = 0;
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
        int ans = 1000000000;
        for (int i = 1; i <= D; i++)
        {
            int T_T;
            scanf("%d", &T_T);
            ans = min(ans, dis[T_T]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
