#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

long long prix[500000];
long long n;
long long num;

void calc(long long x)
{
    num = 0;
    long long temp = n;
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
}

long long phi(long long x)
{
    calc(x);
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
    while (cin >> n && n)
    {
        cout << phi(n) << endl;
    }
    return 0;
}
