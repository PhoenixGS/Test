#include <cstdio>
#include <cstring>

int n, m, q;
int qx[1000005];
int qy[1000005];
bool flag[20005];
int edgenum;
int quesnum;
bool flagX;
int f[20005];
int vet[20005];
int next[20005];
int head[20005];
int cost[20005];
int father[20005];
bool visit[20005];
int qvet[2000005];
int qnext[2000005];
int number[2000005];
int qhead[20005];
int deep[20005];
int ans[1000005];
int fflag[20005];
int root;

int findfather(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    return f[x] = findfather(f[x]);
}

void add(int u, int v, int val)
{
    edgenum++;
    vet[edgenum] = v;
    cost[edgenum] = val;
    next[edgenum] = head[u];
    head[u] = edgenum;
}

void addq(int u, int v, int num)
{
    quesnum++;
    qvet[quesnum] = v;
    qnext[quesnum] = qhead[u];
    number[quesnum] = num;
    qhead[u] = quesnum;
}

void LCA(int u)
{
    fflag[u] = true;
    visit[u] = true;
    for (int i = head[u]; i; i = next[i])
    {
        int v = vet[i];
        if (fflag[v] == false)
        {
            LCA(v);
            if (flagX)
            {
                return;
            }
            f[v] = u;
        }
    }
    for (int i = qhead[u]; i; i = qnext[i])
    {
        if (visit[qvet[i]])
        {
            ans[number[i]] = findfather(qvet[i]);
        }
    }
}

void calc(int root, int k)
{
    deep[root] = k;
    flag[root] = true;
    for (int i = head[root]; i; i = next[i])
    {
        if (flag[i] == false)
        {
            calc(vet[i], k + cost[i]);
        }
    }
}

int main()
{
    edgenum = 0;
    flagX = false;
    /*
    memset(flag, 0, sizeof(flag));
    memset(vet, 0, sizeof(vet));
    memset(next, 0, sizeof(next));
    memset(head, 0, sizeof(head));
    memset(visit, 0, sizeof(visit));
    memset(fflag, 0, sizeof(fflag));
    memset(ans, -1, sizeof(ans));
    */
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, val;
        scanf("%d%d%d", &u, &v, &val);
        add(u, v, val);
        add(v, u, val);
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &qx[i], &qy[i]);
        addq(qx[i], qy[i], i);
        addq(qy[i], qx[i], i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == false)
        {
            calc(i, 0);
        }
        LCA(i);
    }
    for (int i = 1; i <= q; i++)
    {
        if (findfather(qx[i]) != findfather(qy[i]))
        {
            printf("Not connected\n");
        }
        else
        {
            printf("%d\n", deep[qx[i]] + deep[qy[i]] - 2 * deep[ans[i]]);
        }
    }
    return 0;
}
