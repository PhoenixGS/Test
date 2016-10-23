#include <cstdio>
#include <algorithm>

using namespace std;

int s[100000];
int len, n, m;

int check(int T_T)
{
    int ans = 0;
    int O_O = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (s[i] - s[O_O] < T_T)
        {
            ans++;
        }
        else
        {
            O_O = i;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &len, &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }
    sort(s + 1, s + n + 1);
    s[n + 1] = len;
    int l = 0;
    int r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid) >= m)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
