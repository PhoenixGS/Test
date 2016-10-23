#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int v, len;
    node(int _v, int _len)
    {
        v = _v;
        len = _len;
    }
    friend bool operator < (const node &a, const node &b)
    {
        return a.len > b.len;
    }
};

priority_queue<node> heap;
vector<node> vec[100005];
int dis[100005];
bool flag[100005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        vec[u].push_back(node(v, len));
        vec[v].push_back(node(u, len));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1000000000;
        flag[i] = false;
    }
    dis[1] = 0;
    heap.push(node(1, 0));
    while (! heap.empty())
    {
        node tmp = heap.top();
        heap.pop();
        if (! flag[tmp.v])
        {
            int u = tmp.v;
            flag[u] = true;
            for (int i = 0; i < vec[u].size(); i++)
            {
                int v = vec[u][i].v, len = vec[u][i].len;
                if (! flag[v] && dis[u] + len < dis[v])
                {
                    dis[v] = dis[u] + len;
                    heap.push(node(v, dis[v]));
                }
            }
        }
    }
    printf("%d\n", dis[n]);
    return 0;
}
