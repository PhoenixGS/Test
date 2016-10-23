#include <cstdio>
#include <iostream>

using namespace std;

long long x;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &x);
        if (((x % 2 == 1) || (x % 4 == 0)) && (x != 1) && (x != 4)) printf("True\n");
        else printf("False\n");
    }
    return 0;
}
