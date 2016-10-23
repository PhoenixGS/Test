#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
int Ans;

struct text
{
    int v[1000];
    int pre;
    int k;
};

bool check(text x, text y)
{
    for (int i = 1; i <= n + m + 1; i++)
    {
        if (x.v[i] != y.v[i])
        {
            return false;
        }
    }
    return true;
}

text que[100000];

void print(text x)
{
    if (x.pre != 0)
    {
        print(que[x.pre]);
    }
    Ans++;
    for (int i = 1; i <= n + m + 1; i++)
    {
        printf("%d", x.v[i]);
    }
    printf("\n");
}

int main()
{
    Ans = 0;
    scanf("%d%d", &n, &m);
    text s, t;
    for (int i = 1; i <= n; i++)
    {
        s.v[i] = 1;
    }
    for (int i = n + 2; i <= n + m + 1; i++)
    {
        s.v[i] = 2;
    }
    s.pre = 0;
    s.k = n + 1;
    for (int i = 1; i <= m; i++)
    {
        t.v[i] = 2;
    }
    for (int i = m + 2; i <= n + m + 1; i++)
    {
        t.v[i] = 1;
    }
    int head = 0;
    int tail = 0;
    que[head] = s;
    while (head <= tail)
    {
        text now;
        now = que[head];
        now.pre = head;
        if (now.k > 1)
        {
            swap(now.v[now.k - 1], now.v[now.k]);
            now.k--;
        }
        if (check(now, t))
        {
            print(now);
            printf("%d\n", Ans);
            return 0;
        }
        tail++;
        que[tail] = now;

        now = que[head];
        now.pre = head;
        if (now.k <= n + m)
        {
            swap(now.v[now.k + 1], now.v[now.k]);
            now.k++;
        }
        if (check(now, t))
        {
            print(now);
            printf("%d\n", Ans);
            return 0;
        }
        tail++;
        que[tail] = now;

        now = que[head];
        now.pre = head;
        if (now.k > 2 && now.v[now.k - 1] != now.v[now.k - 2])
        {
            swap(now.v[now.k - 2], now.v[now.k]);
            now.k -= 2;
        }
        if (check(now, t))
        {
            print(now);
            printf("%d\n", Ans);
            return 0;
        }
        tail++;
        que[tail] = now;

        now = que[head];
        now.pre = head;
        if (now.k < n + m && now.v[now.k + 1] != now.v[now.k + 2])
        {
            swap(now.v[now.k + 2], now.v[now.k]);
            now.k += 2;
        }
        if (check(now, t))
        {
            print(now);
            printf("%d\n", Ans);
            return 0;
        }
        tail++;
        que[tail] = now;
        head++;
    }
}
