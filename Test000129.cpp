#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

string st;
int ans;
int T;

int main()
{
    while (cin >> st)
    {
        int len = st.length();
        ans = 0;
        for (int i = 0; i < len; i++)
        {
            int l, r;
            l = i - 1;
            r = i + 1;
            T = 1;
            while (l >= 0 && r < len && st[l] == st[r])
            {
                T += 2;
                l--;
                r++;
            }
            ans = max(ans, T);
            l = i;
            r = i + 1;
            T = 0;
            while (l >= 0 && r < len && st[l] == st[r])
            {
                T += 2;
                l--;
                r++;
            }
            ans = max(ans, T);
        }
        printf("%d\n", ans);
    }
    return 0;
}
