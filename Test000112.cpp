#include <cstdio>
#include <algorithm>

using namespace std;

int x[200000];
int n;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x[i]);
        }
        sort(x + 1, x + n + 1);
        int l = 0;
        int r = 1000000000;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            long long total = 0;
            int head = 1;
            int tail = 1;
            while (tail <= n)
            {
                while (x[tail] - x[head] > mid)
                {
                    head++;
                }
                total += tail - head;
                tail++;
            }
            long long N = (long long)n * (n - 1) / 2;
            if (total < (N + 1) / 2)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}
