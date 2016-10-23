#include <cstdio>

int x[2000000];
int f[2000000];
int que[2000000];

int main()
{
    int n, L, R;
    scanf("%d%d%d", &n, &L, &R);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }    
    int head = 0;
    int tail = -1;
    for (int i = 1; i <= n; i++)
    {
        //printf("%d:", i);
        //for (int j = head; j <= tail; j++)
        //{
        //    printf("%d ", que[j]);
        //}
        //printf("\n");
        if (i > L)
        {
            while (head <= tail && f[que[tail]] > f[i - L - 1])
            {
                tail--;
            }
            tail++;
            que[tail] = i - L - 1;
        }
        while (head <= tail && i - que[head] - 1 > R)
        {
            head++;
        }
        //for (int j = head; j <= tail; j++)
        //{
        //    printf("%d ", que[j]);
        //}
        //printf("\n");
        if (head <= tail && f[que[head]] != 1000000000) f[i] = f[que[head]] + x[i];
        else f[i] = 1000000000;
        //printf("%d %d\n", i, f[i]);
    }
    if (f[n] >= 1000000000) printf("-1\n");
    else printf("%d\n", f[n]);
    return 0;
}
