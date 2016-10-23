#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int phi[4000000];
bool vis[4000000];
int pr[4000000];
long long s[4000000];

int main()
{
    int num = 0;
    int n = 3000000;
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
    for (int i = 1; i <= 3000000; i++)
    {
        s[i] = s[i - 1] + phi[i];
    }
    int l, r;
    while (scanf("%d%d", &l, &r) == 2)
    {
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
