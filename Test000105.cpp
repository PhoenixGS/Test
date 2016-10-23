#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long sum[600000];
long long x[200000];
long long tag[600000];
int n, _;

void down(int u, int l, int r)
{
    if (! tag[u])
    {
        return;
    }
    sum[u] = r - l + 1 - sum[u];
    if (l != r)
    {
        tag[u << 1] ^= tag[u];
        tag[u << 1 | 1] ^= tag[u];
    }
    tag[u] = 0;
}

void up(int u, int l, int r)
{
    int mid = (l + r) >> 1;
    down(u << 1, l, mid);
    down(u << 1 | 1, mid + 1, r);
    sum[u] = sum[u << 1] + sum[u << 1 | 1];
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
    up(u, l, r);
}

void change(int u, int l, int r, int X, int Y)
{
    down(u, l, r);
    if (X > r || Y < l)
    {
        return;
    }
    if (X <= l && Y >= r)
    {
        tag[u] ^= 1;
        down(u, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    change(u << 1, l, mid, X, Y);
    change(u << 1 | 1, mid + 1, r, X, Y);
    up(u, l, r);
}

long long find(int u, int l, int r, int X, int Y)
{
    down(u, l, r);
    if (X > r || Y < l)
    {
        return 0;
    }
    if (X <= l && Y >= r)
    {
        return sum[u];
    }
    int mid = (l + r) >> 1;
    return find(u << 1, l, mid, X, Y) + find(u << 1 | 1, mid + 1, r, X, Y);
}

int main()
{
    scanf("%d%d", &n, &_);
    build(1, 1, n);
    while (_--)
    {
        int O_O;
        scanf("%d", &O_O);
        if (O_O == 0)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            change(1, 1, n, l, r);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", find(1, 1, n, l, r));
        }
    }
    return 0;
}
