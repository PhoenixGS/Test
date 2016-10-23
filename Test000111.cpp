#include <cstdio>
#include <algorithm>

using namespace std;

int x[2000];
int y[2000];
double z[2000];
int n, k;

int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        if (n == 0 && k == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &y[i]);
        }
        double l = 0.0;
        double r = 1.0;
        while (r - l >= 1e-8)
        {
            double mid = (l + r) / 2.0;
            for (int i = 1; i <= n; i++)
            {
                z[i] = x[i] - mid * y[i];
            }
            sort(z + 1, z + n + 1);
            double total = 0.0;
            for (int i = n; i > k; i--)
            {
                total += z[i];
            }
            if (total > 0)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        printf("%.f\n", l * 100);
    }
    return 0;
}
