#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int S[1000];
int T[1000];
int x[1000];
bool flag[1000];
string st;
int len;
int ans;
int n;

void calc()
{
    int H = 0;
    int top = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (st[i] == 'X')
        {
            top++;
            S[top] = T[H];
            H++;
        }
        if (st[i] == 'A')
        {
            top--;
            S[top] = S[top] + S[top + 1];
        }
        if (st[i] == 'B')
        {
            top--;
            S[top] = max(S[top], S[top + 1]);
        }
    }
    ans = max(ans, S[top]);
}

void dfs(int k)
{
    if (k == n)
    {
        calc();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (! flag[i])
        {
            T[k] = x[i];
            flag[i] = true;
            dfs(k + 1);
            flag[i] = false;
        }
    }
}

int main()
{
    cin >> st;
    len = st.length();
    n = 0;
    for (int i = 0; i < len; i++)
    {
        if (st[i] == 'X')
        {
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    ans = 0;
    dfs(0);
    printf("%d\n", ans);
}
