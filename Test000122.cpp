#include <cstdio>

long long x[200000];
long long n, m;

bool check(long long T)
{
    long long ans = 0;
    long long now = 1;
    for (long long i = 1; i <= n; i++)
    {
        if (x[i] > T)
        {
            return false;
        }
        if (now + x[i] <= T)
        {
            now += x[i];
        }
        else
        {
            now = x[i];
            ans++;
        }
    }
    if (ans <= m)
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
    scanf("%lld%lld", &n, &m);
    long long total = 0;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i]);
        total += x[i];
    }
    long long l = 0;
    long long r = total;
    while (l < r)
    {
        long long mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", l);
    return 0;
}
