#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int x[100050],tmpA[100050],tmpB[100050];
int lastA,lastB,n,ans;

void dfs(int k, int s)
{
    if (k == n)
    {
        ans = max(ans, s);
        return;
    }
    lastA++;
    tmpA[lastA] = x[k];
    if (lastA == 1)
    {
        dfs(k + 1, s + 1);
    }
    if (lastA == 2)
    {
        if (tmpA[lastA - 1] == tmpA[lastA])
        {
            dfs(k + 1, s + 1);
        }
        else
        {
            dfs(k + 1, s + 2);
        }
    }
    if (lastA > 2)
    {
        int t = 0;
        if (tmpA[lastA - 2] != tmpA[lastA - 1])
        {
            t++;
        }
        if (tmpA[lastA - 1] != tmpA[lastA])
        {
            t++;
        }
        if (tmpA[lastA - 2] != tmpA[lastA])
        {
            t++;
        }
        if (t == 0)
        {
            dfs(k + 1, s + 1);
        }
        if (t == 2)
        {
            dfs(k + 1, s + 2);
        }
        if (t == 3)
        {
            dfs(k + 1, s + 3);
        }
    }
    lastA--;
    lastB++;
    tmpB[lastB] = x[k];
    if (lastB == 1)
    {
        dfs(k + 1, s + 1);
    }
    if (lastB == 2)
    {
        if (tmpB[lastB - 1] != tmpB[lastB])
        {
            dfs(k + 1, s + 2);
        }
        else
        {
            dfs(k + 1, s + 1);
        }
    }
    if (lastB > 2)
    {
        int t = 0;
        if (tmpB[lastB - 2] != tmpB[lastB - 1])
        {
            t++;
        }
        if (tmpB[lastB - 1] != tmpB[lastB])
        {
            t++;
        }
        if (tmpB[lastB - 2] != tmpB[lastB])
        {
            t++;
        }
        if (t == 0)
        {
            dfs(k + 1, s + 1);
        }
        if (t == 2)
        {
            dfs(k + 1, s + 2);
        }
        if (t == 3)
        {
            dfs(k + 1, s + 3);
        }
    }
    lastB--;
}

int main()
{
    ans=0;
    scanf("%d", &n);
    char s1[1000005];
    scanf("%s",s1);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'M')
        {
            x[i] = 0;
        }
        if (s1[i] == 'B')
        {
            x[i] = 1;
        }
        if (s1[i] == 'F')
        {
            x[i] = 2;
        }
    }
    ans = 0;
    lastA = 0;
    lastB = 0;
    dfs(0, 0);
    printf("%d\n", ans);
}
