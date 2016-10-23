#include <cstdio>
#include <cstring>

int n, m;
int edgenum;
int head[1000];
bool flag[1000];
int in[1000];
int vet[1000000];
int next[1000000];
int ans[1000];

void add(int u, int v)
{
    edgenum++;
    vet[edgenum] = v;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        edgenum = 0;
        memset(head, 0, sizeof(head));
        memset(in, 0, sizeof(in));
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            in[v]++;
        }
        int times = 0;
        for (int T_T = 1; T_T <= n; T_T++)
        {
            int O_O;
            for (O_O = 1; in[O_O] != 0 || flag[O_O] != false; O_O++);
            //printf("%d %d\n", O_O, flag[O_O]);
            times++;
            ans[O_O] = times;
            flag[O_O] = true;
            for (int i = head[O_O]; i; i = next[i])
            {
                int v = vet[i];
                if (flag[v] == false)
                {
                    in[v]--;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
    }
}
