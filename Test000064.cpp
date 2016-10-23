#include <cstdio>
#include <queue>

using namespace std;

int que[2000000];
int x[2000000];
int f[2000000];

int main()
{
    int n, L, R;
    scanf("%d%d%d", &n, &L, &R);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
        f[i] = 1000000000;
    }
    f[0] = 0;
    int head = 0;
    int tail = -1;
    for (int i = 1; i <= n; i++)
    {
        while (head <= tail && i - R - 1 > que[head])
        {
            head++;
        }
        if (i - L - 1 >= 0)
        {
            while (head <= tail && f[i - L - 1] <= f[que[tail]])
            {
                tail--;
            }
            tail++;
            que[tail] = i - L - 1;
        }
        if (head <= tail)
        {
            f[i] = f[que[head]] + x[i];
        }
    }
    if (f[n] >= 1000000000) printf("-1\n");
    else printf("%d\n", f[n]);
    return 0;
}
