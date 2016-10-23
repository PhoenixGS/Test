#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 4 == 0 || n % 4 == 3)
    {
        printf("0\n");
    }
    if (n % 4 == 1 || n % 4 == 2)
    {
        printf("1\n");
    }
    return 0;
}
