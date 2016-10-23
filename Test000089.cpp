#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int p[10000];
long long dp[20][10000];
int n, m;

int main()
{
    while (scanf("%d%d", &n, &m) != EOF && n && m)
    {
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        int k = 1 << m;
        p[0] = 1;
        for (int i = 1; i < k; i++)
        {
            int t = i & (-i);
            if (i & (2 * t))
            {
                p[i] = p[i - 3 * t];
            }
        }
        dp[0][k - 1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (dp[i][j])
                {
                    for (int z = j; ; z = (z - 1) & j)
                    {
                        if (p[z])
                        {
                            dp[i + 1][(k - 1 - j) | z] += dp[i][j];
                            if (z == 0)
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << dp[n][k - 1] << endl;
    }
    return 0;
}
