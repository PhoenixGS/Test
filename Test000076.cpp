#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int phi[100000];
bool vis[100000];
int pr[100000];

int main()
{
    int num = 0;
    int n = 32767;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (! vis[i])
        {
            pr[++num] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= num && pr[j] * i <= n; j++)
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
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", phi[x]);
    }
    return 0;
}
