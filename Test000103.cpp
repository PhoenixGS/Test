#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int sum[600000];
int x[200000];
int n;

void change(int u, int l, int r, int x, int y, int X)
{
    if (x > r || y < l)
    {
        return;
    }
    if (x <= l && y >=r)
    {
        sum[u] += X;
        return;
    }
    int mid = (l + r) >> 1;
    change(u << 1, l, mid, x, y, X);
    change(u << 1 | 1, mid + 1, r, x, y, X);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        sum[u] = x[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int find(int u, int l, int r, int X)
{
    if (l == r)
    {
        return sum[u];
    }
    int mid = (l + r) >> 1;
    if (X <= mid)
    {
        return find(u << 1, l, mid, X) + sum[u];
    }
    else
    {
        return find(u << 1 | 1, mid + 1, r, X) + sum[u];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    build(1, 1, n);
    int _;
    scanf("%d", &_);
    while (_--)
    {
        int O_O;
        scanf("%d", &O_O);
        if (O_O == 1)
        {
            int l, r, T_T;
            scanf("%d%d%d", &l, &r, &T_T);
            change(1, 1, n, l, r, T_T);
        }
        else
        {
            int T_T;
            scanf("%d", &T_T);
            printf("%d\n", find(1, 1, n, T_T));
        }
    }
    return 0;
}
