#include <cstdio>

void print(int x)
{
    if (x >= 10)
    {
        printf("%d", x);
    }
    else
    {
        printf("0%d", x);
    }
}

int main()
{
    int sx, sy, sz, ex, ey, ez;
    scanf("%d:%d:%d", &sx, &sy, &sz);
    scanf("%d:%d:%d", &ex, &ey, &ez);
    int S = sx * 3600 + sy * 60 + sz;
    int E = ex * 3600 + ey * 60 + ez;
    int ans = (E - S + 86400) % 86400;
    if (ans == 0)
    {
        printf("24:00:00\n");
    }
    else
    {
        int ansx = ans / 3600;
        int ansy = ans % 3600 / 60;
        int ansz = ans % 60;
        print(ansx);
        printf(":");
        print(ansy);
        printf(":");
        print(ansz);
        printf("\n");
    }
    return 0;
}
