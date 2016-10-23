#include <cstdio>

int x[4000000];
int que[4000000];
int id[4000000];
int num[4000000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    int head = 1;
    int tail = 0;
    int now = 1;
    while (now <= n)
    {
        if (id[tail] - id[head] + 1 > m)
        {
            head++;
        }
        printf("%d\n", num[head]);
        while (tail >= head && x[now] < num[tail])
        {
            tail--;
        }
        tail++;
        num[tail] = x[now];
        id[tail] = now;
        now++;
    }
    return 0;
}
