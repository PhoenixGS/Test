#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int x[100];
long long f[100000][20];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++)
    {
        f[1 << i][i] = 1;
    }
    for (int cas = 1; cas < (1 << n) - 1; cas++)
    {
        for (int i = 0; i < n; i++)
        {
            if (cas & (1 << i))
            {
                for (int j = 0; j < n; j++)
                {
                    if ((! (cas & (1 << j))) && (abs(x[i] - x[j]) > k))
                    {
                        f[cas | (1 << j)][j] += f[cas][i];
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += f[(1 << n) - 1][i];
    }
    cout << ans << endl;
    return 0;
}
