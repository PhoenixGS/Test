#include <cstdio>
#include <algorithm>

using namespace std;

int temp[100];
int x[100];

int check(int t)
{
    int tmp = t;
    for (int i = 1; i <= 20; i++)
    {
        temp[i] = x[i];
    }
    if (t == 1)
    {
        temp[0] = 1 - temp[0];
        temp[1] = 1 - temp[1];
        temp[2] = 1 - temp[2];
    }
    for (int i = 2; i <= 20; i++)
    {
        if (temp[i - 1] == 1)
        {
            tmp++;
            temp[i - 1] = 1 - temp[i - 1];
            temp[i] = 1 - temp[i];
            temp[i + 1] = 1 - temp[i + 1];
        }
    }
    bool flag = true;
    for (int i = 1; i <= 20; i++)
    {
        if (temp[i] == 1)
        {
            flag = false;
        }
    }
    if (flag == false)
    {
        return 2000000000;
    }
    return tmp;
}

int main()
{
    while (scanf("%d", &x[1]) == 1)
    {
        for (int i = 2; i <= 20; i++)
        {
            scanf("%d", &x[i]);
        }
        int ans = min(check(0), check(1));
        printf("%d\n", ans);
    }
    return 0;
}
