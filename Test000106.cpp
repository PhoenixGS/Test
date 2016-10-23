#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int lmax, rmax, sum, zmax;
};

node t[5000000];
int x[1000000];
int n, _;

node merge(node a, node b)
{
    node c;
    c.sum = a.sum + b.sum;
    c.lmax = max(a.lmax, a.sum + b.lmax);
    c.rmax = max(b.rmax, b.sum + a.rmax);
    c.zmax = max(max(a.zmax, b.zmax), a.rmax + b.lmax);
    return c; 
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        t[u].rmax = t[u].zmax = t[u].lmax = x[l];
        t[u].sum = x[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

node find(int u, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return t[u];
    }
    if (x > r || y < l)
    {
        return (node){-1000000000, -1000000000, -1000000000, -1000000000};
    }
    int mid = (l + r) >> 1;
    return merge(find(u << 1, l, mid, x, y), find(u << 1 | 1, mid + 1, r, x, y));
}

void change(int u, int l, int r, int O_O, int w)
{
    if (l == r)
    {
        x[l] = w;
        t[u].rmax = t[u].zmax = t[u].lmax = x[l];
        t[u].sum = x[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (O_O <= mid)
    {
        change(u << 1, l, mid, O_O, w);
    }
    else
    {
        change(u << 1 | 1, mid + 1, r, O_O, w);
    }
    t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

int main()
{
    scanf("%d%d", &n, &_);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    build(1, 1, n);
    while (_--)
    {
        int T_T;
        scanf("%d", &T_T);
        if (T_T == 1)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            node a = find(1, 1, n, l, r);
            printf("%d\n", a.zmax);
        }
        else
        {
            int O_O, w;
            scanf("%d%d", &O_O, &w);
            change(1, 1, n, O_O, w);
        }
    }
}
