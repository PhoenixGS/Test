#include <cstdio>
#include <algorithm>

using namespace std;

int f[30000];
int d[30000];

struct test
{
    int x, y, z;
};

test x[200000];

bool comp(test x, test y)
{
    return x.z > y.z;
}

int findf(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    int y = f[x];
    f[x] = findf(f[x]);
    d[x] = (d[x] + d[y]) % 2;
    return f[x];
}

void unionn(int xx, int yy, int xxx, int yyy)
{
    f[xx] = yy;
    d[xx] = (- d[xxx] + d[yyy] + 1) % 2;
}

int main()
{
    int ans = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x[i].x, &x[i].y, &x[i].z);
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        d[i] = 0;
    }
    sort(x + 1, x + m + 1, comp);
    for (int i = 1; i <= m; i++)
    {
        int xx = findf(x[i].x);
        int yy = findf(x[i].y);
        if (xx != yy)
        {
            unionn(xx, yy, x[i].x, x[i].y);
        }
        else
        {
            if (d[x[i].x] == d[x[i].y])
            {
                ans = x[i].z;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
