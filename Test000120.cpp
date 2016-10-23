#include <cstdio>

double x[100][100];
double dis[20000];
int vet[1000000];
double val[1000000];
int next[1000000];
int head[20000];
double F[100];
int que[20000];
bool flag[20000];
int n, m;
int edgenum;
int s, t;

void add(int u, int v, double cost)
{
    edgenum++;
    vet[edgenum] = v;
    val[edgenum] = cost;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

int main()
{
    scanf("%d%d", &n, &m);
    F[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        F[i] = F[i - 1] * 0.5;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double T_T;
            scanf("%lf", &T_T);
            if (T_T != 0)
            {
                for (int pre = 0; pre <= m; pre++)
                {
                    for (int now = pre; now <= m; now++)
                    {
                        add(pre * n + i, now * n + j, F[now - pre] * T_T);
                    }
                }
            }
        }
    }
    s = 1;
    t = n * (m + 1);
    for (int i = 1; i <= n * (m + 1); i++)
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
    printf("%.2f\n", dis[t]);
    return 0;
}
