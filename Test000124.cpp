#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int prime[400000];
int sum[400000];
bool flag[400000];
int n, m;
int primenum;

void calc(int V, int F)
{
    int temp = V;
    for (int i = 1; i <= primenum && prime[i] <= sqrt(V) && prime[i] <= temp; i++)
    {
        int pr = prime[i];
        while (temp >= pr && temp % pr == 0)
        {
            temp = temp / pr;
            sum[pr] = sum[pr] + F;
        }
    }
    if (temp != 1)
    {
        sum[temp] = sum[temp] + F; 
    }
}

long long T_T(int x, int y, long long mod)
{
    long long temp = x;
    long long ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = ans * temp % mod;
        }
        temp = temp * temp % mod;
        y >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1)
    {
        printf("1\n");
        return 0;
    }
    if (n == 1 || m == 1)
    {
        printf("0\n");
        return 0;
    }
    if (n == 2 || m == 2)
    {
        printf("1\n");
        return 0;
    }
    n -= 2;
    m -= 2;
    if (n > m)
    {
        swap(n, m);
    }
    primenum = 0;
    for (int i = 2; i <= n + m; i++)
    {
        if (! flag[i])
        {
            primenum++;
            prime[primenum] = i;
            for (int j = 2; i * j <= n + m; j++)
            {
                flag[i * j] = true;
            }
        }
    }
    for (int i = n + m; n + m - i + 1 <= n; i--)
    {
        calc(i, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        calc(i, -1);
    }
    long long ans = 1;
    for (int i = 1; i <= primenum; i++)
    {
        //for (int j = 1; j <= sum[prime[i]]; j++)
        //{
        //    ans = ans * prime[i] % 1000000007;
        //}
        ans = ans * T_T(prime[i], sum[prime[i]], 1000000007) % 1000000007;
    }
    printf("%lld\n", ans);
    return 0;
}
