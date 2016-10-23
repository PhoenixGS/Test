#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int total;
int n;
int f[400000];
int c[1000];
int s[1000];

void add(int X)
{
    for (int i = T; i >= X; i--)
    {
        f[i] = f[i] | f[i - X];
    }
}

int main()
{
    scanf("%d", &n);
    while (n != -1)
    {
        total = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &c[i], &s[i]);
            total += c[i] * s[i];
        }
        T = total / 2;
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s[i]; j *= 2)
            {
                add(j * c[i]);
                s[i] -= j;
            }
            if (s[i])
            {
                add(s[i] * c[i]);
            }
        }
        int ans;
        for (ans = T; ! f[ans]; ans--);
        printf("%d %d\n", total - ans, ans);
        scanf("%d", &n);
    }
    return 0;
}
