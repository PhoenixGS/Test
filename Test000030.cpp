#include <cstdio>
 
int n, L;
long long x[60000];
long long s[60000];
long long que[60000];
long long f[60000];
 
long long g(int x)
{
    return s[x] + x;
}
 
long long h(int x)
{
    return s[x] + x + 1 + L;
}
 
long long up(int x, int y)
{
    return f[y] - f[x] + h(y) * h(y) - h(x) * h(x);
}
 
long long down(int x, int y)
{
    return 2 * (h(y) - h(x));
}
 
//long long calc(int x, int y)
//{
//  return f[x] + (g(y) - h(x)) * (g(y) - h(x));
//}
 
int main()
{
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i]);
        s[i] = s[i - 1] + x[i];
    }
    int head = 0;
    int tail = 0;
    que[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head + 1 <= tail && g(i) * down(que[head], que[head + 1]) >= up(que[head], que[head + 1]))
        {
            head++;
        }
        f[i] = f[que[head]] + (g(i) - h(que[head])) * (g(i) - h(que[head]));
        while (head + 1 <= tail && up(que[tail - 1], que[tail]) * down(que[tail], i) <= up(que[tail], i) * down(que[tail - 1], que[tail]))
        {
            tail--;
        }
        tail++;
        que[tail] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}