#include <cstdio>

int x[600000];
int sum[600000];
int f[600000];
int que[600000];

int up(int j, int k)
{
    return f[j] + sum[j] * sum[j] - f[k] - sum[k] * sum[k];
}

int down(int j, int k)
{
    return 2 * (sum[j] - sum[k]);
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        sum[0] = 0;
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x[i]);
            sum[i] = sum[i - 1] + x[i];
        }
        int head = 0;
        int tail = 0;
        que[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            while (head < tail && up(que[head + 1], que[head]) < sum[i] * down(que[head + 1], que[head]))
            {
                head++;
            }
            f[i] = f[que[head]] + m + (sum[i] - sum[que[head]]) * (sum[i] - sum[que[head]]);
            while (head < tail && up(i, que[tail]) * down(que[tail], que[tail - 1]) <= up(que[tail], que[tail - 1]) * down(i, que[tail]))
            {
                tail--;
            }
            tail++;
            que[tail] = i;
        }
        printf("%d\n", f[n]);
    }
}
