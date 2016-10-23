#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

long long n, k;
long long ans;
long long prix[500000];
int num;

long long phi(long long x)
{
    long long tmp = x;
    for (int i = 1; i <= num; i++)
    {
        if (x % prix[i] == 0)
        {
            tmp = tmp * (prix[i] - 1) / prix[i] % 1000000007;
        }
    }
    return tmp;
}

int main()
{
    while (cin >> n >> k)
    {
        ans = 0;
        if (k >= 3)
        {
            printf("0\n");
            continue;
        }
        if (k == 2)
        {
            printf("1\n");
            continue;
        }
        num = 0;
        int temp = n;
        for (long long i = 2; i <= sqrt(n); i++)
        {
            if (temp % i == 0)
            {
                while (temp % i == 0)
                {
                    temp = temp / i;
                }
                num++;
                prix[num] = i;
            }
        }
        if (temp != 1)
        {
            num++;
            prix[num] = temp;
        }
        for (long long i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (i * i == n)
                {
                    ans = (ans + phi(i) * phi(n / i)) % 1000000007;
                }
                else
                {
                    ans = (ans + 2 * phi(i) * phi(n / i)) % 1000000007;
                } 
            }
        }
        cout << ans << endl;
    }
}
