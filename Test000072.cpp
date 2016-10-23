#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long temp = 1;
    for (int i = 1; i <= n; i++)
    {
        temp = temp * i;
        while (temp % 10 == 0)
        {
            temp /= 10;
        }
        temp = temp % 1000000000000;
    }
    cout << temp % 10 << endl;
    return 0;
}
