#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct V
{
    int s, id;
    double times;
};

bool comp(V x, V y)
{
    return x.times < y.times || x.times == y.times && x.s > y.s || x.times == y.times && x.s == y.s && x.id > y.id;
}

int dis[50000];
bool flag[50000];
int head[50000];
int next[100000];
int vet[100000];
int val[100000];
int que[20000];
V F[20000];
int n, m, s, _;
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
    while (scanf("%d%d%d", &n, &_, &m) != EOF)
    {
        memset(head, 0, sizeof(head));
        edgenum = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            add(v, u, cost);
        }
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 1000000000;
        }
        scanf("%d", &s);
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
        for (int i = 1; i <= _; i++)
        {
            int T_T;
            scanf("%d", &T_T);
            F[i].s = dis[T_T];
        }
        for (int i = 1; i <= _; i++)
        {
            int T_T;
            scanf("%d", &T_T);
            F[i].times = (double)F[i].s / T_T;
        }
        for (int i = 1; i <= _; i++)
        {
            F[i].id = i;
        }
        sort(F + 1, F + _ + 1, comp);
        if (F[1].s == 1000000000)
        {
            printf("No one\n");
        }
        else
        {
            printf("%d\n", F[1].id);
        }
    }
    return 0;
}
