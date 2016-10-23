#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const long long nn = 4000000;
long long pr[400000];
bool vis[4000005];
long long phi[4000005];
long long f[4000005];
long long s[4000005];
int num;

int main()
{
    num = 0;
    phi[1] = 1;
    for (long long i = 2; i <= nn; i++)
    {
        if (! vis[i])
        {
            pr[++num] = i;
            phi[i] = i - 1;
        }
        for (long long j = 1; j <= num && pr[j] * i <= nn; j++)
        {
            vis[pr[j] * i] = 1;
            if (i % pr[j] == 0)
            {
                phi[pr[j] * i] = phi[i] * pr[j];
                break;
            }
            else
            {
                phi[pr[j] * i] = phi[pr[j]] * phi[i];
            }
        }
    }
    for (long long k = 1; k <= nn; k++)
    {
        for (long long kk = 2; kk * k <= nn; kk++)
        {
            f[kk * k] += phi[kk] * k;
        }
    }
    for (long long i = 1; i <= nn; i++)
    {
        s[i] = s[i - 1] + f[i];
    }
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        printf("%lld\n", s[n]);
    }
    return 0;
}
