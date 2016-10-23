#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int _;
int f[3000][3000];

int main()
{
    scanf("%d", &_);
    while (_--)
    {
        string x, y, s;
        cin >> x >> y >> s;
        if (x.length() + y.length() != s.length())
        {
            printf("No\n");
            continue;
        }
        memset(f, 0, sizeof(f));
        f[0][0] = true;
        for (int i = 0; i <= x.length(); i++)
        {
            for (int j = 0; j <= y.length(); j++)
            {
                if (i > 0 && x[i - 1] == s[i + j - 1])
                {
                    f[i][j] = f[i][j] | f[i - 1][j];
                }
                if (j > 0 && y[j - 1] == s[i + j - 1])
                {
                    f[i][j] = f[i][j] | f[i][j - 1];
                }
            }
        }
        if (f[x.length()][y.length()])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
