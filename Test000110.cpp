#include <cstdio>

int x[200000];
int n, m;

bool check(int T_T)
{
    int O_O = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] > T_T)
        {
            return false;
        }
        if (O_O + x[i] > T_T)
        {
            ans++;
            O_O = x[i];
        }
        else
        {
            O_O += x[i];
        }
    }
    if (ans + 1 <= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x[i]);
            total += x[i];
        }
        int l = 0;
        int r = total;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}
