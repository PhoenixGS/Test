#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int minx = 1000000000;
    int maxx = 0;
    int miny = 1000000000;
    int maxy = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > maxx)
        {
            maxx = x;
        }
        if (x < minx)
        {
            minx = x;
        }
        if (y > maxy)
        {
            maxy = y;
        }
        if (y < miny)
        {
            miny = y;
        }
    }
    printf("%d\n", (maxx - minx) * (maxy - miny));
}
