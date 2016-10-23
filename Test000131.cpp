#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
char str[3000000];
char s[3000000];
int f[3000000];
int id, ans;

int main()
{
    while (scanf("%s", str) != EOF)
    {
        n = strlen(str);
        for (int i = 0; i < n; i++)
        {
            s[i * 2 + 1] = str[i];
        }
        for (int i = 0; i <= 2 * n; i += 2)
        {
            s[i] ='#';
        }
        ans = 1;
        id = 1;
        f[1] = 1;
        for (int i = 2; i < 2 * n; i++)
        {
            if (id + f[id] - 1 >= i)
            {
                f[i] = min(f[id * 2 - i], id + f[id] - i);
            }
            else
            {
                f[i] = 1;
            }
            while (s[i + f[i]] == s[i - f[i]] && i + f[i] <= 2 * n && i - f[i] >= 0)
            {
                f[i]++;
            }
            if (i & 1)
            {
                ans = max(ans, f[i] / 2 * 2 - 1);
            }
            else
            {
                ans = max(ans, f[i] / 2 * 2);
            }
            if (f[i] + i > id + f[id])
            {
                id = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
