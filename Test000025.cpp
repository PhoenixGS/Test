#include <cstdio>

int x[2000000];
int f[2000000];
int que[2000000];

int main()
{
    int n, L, R;
    scanf("%d%d%d", &n, &L, &R);
    int head = 0;
    int tail = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= L; i++)
    {
        f[i] = 1000000000;
    }
    for (int i = L + 1; i <= n; i++)
    {
        while (head <= tail && f[que[tail]] > f[i - L - 1])
        {
            tail--;
        }
        tail++;
        que[tail] = i - L - 1;
        while (head <= tail && i - que[head] > R + 1)
        {
            head++;
        }
        f[i] = f[que[head]] + x[i];
    }
    if (f[n] >= 1000000000) printf("-1\n");
    else printf("%d\n", f[n]);
    return 0;
}
