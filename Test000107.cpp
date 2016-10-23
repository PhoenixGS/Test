#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int minx[300000];
int maxx[300000];
int x[300000];
int ans1, ans2;
int n, _;

void build(int u, int l, int r)
{
    if (l == r)
    {
        minx[u] = x[l];
        maxx[u] = x[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    minx[u] = min(minx[u << 1], minx[u << 1 | 1]);
    maxx[u] = max(maxx[u << 1], maxx[u << 1 | 1]);
}

void find(int u, int l, int r, int X, int Y)
{
    if (X > r || Y < l)
    {
        return;
    }
    if (X <= l && Y >= r)
    {
        ans1 = max(ans1, maxx[u]);
        ans2 = min(ans2, minx[u]);
        return;
    }
    int mid = (l + r) >> 1;
    find(u << 1, l, mid, X, Y);
    find(u << 1 | 1, mid + 1, r, X, Y);
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
        int l, r;
        scanf("%d%d", &l, &r);
        ans1 = 0;
        ans2 = 1000000000;
        find(1, 1, n, l, r);
        printf("%d\n", ans1 - ans2);
    }
    return 0;
}
