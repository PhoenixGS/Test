#include <cstdio>
#include <iostream>

using namespace std;

long long ans;
long long f[200000];
long long c[5];
long long d[5];

void dfs(long long s, long long z, long long k)
{
    if (s < 0)
    {
        return;
    }
    if (k == 5)
    {
        ans += z * f[s];
        return;
    }
    dfs(s, z, k + 1);
    dfs(s - (d[k] + 1) * c[k], z * -1, k + 1);
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        scanf("%d", &c[i]);
    }
    int _;
    scanf("%d", &_);
    f[0] = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = c[i]; j <= 100000; j++)
        {
            f[j] += f[j - c[i]];
        }
    }
    while (_--)
    {
        ans = 0;
        for (int i = 1; i <= 4; i++)
        {
            scanf("%d", &d[i]);
        }
        int s;
        scanf("%d", &s);
        dfs(s, 1, 1);
        cout << ans << endl;
    }
    return 0;
}
