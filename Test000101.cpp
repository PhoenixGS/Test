#include <cstdio>
#include <iostream>

using namespace std;

int vis[16][16][16][16][16][6];
int dp[16][16][16][16][16][6];
int s[10];
int ss[10];
int n;

int dfs(int *s, int t)
{
    if (vis[s[1]][s[2]][s[3]][s[4]][s[5]][t])
    {
        return dp[s[1]][s[2]][s[3]][s[4]][s[5]][t];
    }
    int ss[6];
    int ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        ss[i] = s[i];
    }
    if (s[1] + s[2] + s[3] + s[4] + s[5] == 0)
    {
        return 1;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (ss[i])
        {
            int tmp = ss[i];
            ss[i]--;
            ss[i - 1]++;
            ans = (ans + (long long)dfs(ss, i - 1) * (tmp - (i == t))) % 1000000007;
            ss[i]++;
            ss[i - 1]--;
        }
    }
    vis[s[1]][s[2]][s[3]][s[4]][s[5]][t] = 1;
    dp[s[1]][s[2]][s[3]][s[4]][s[5]][t] = ans;
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int T_T;
        scanf("%d", &T_T);
        s[T_T]++;
    }
    cout << dfs(s, 0) << endl;
    return 0;
}
