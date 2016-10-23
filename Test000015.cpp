#include <cstdio>

int ans;
int x[50000];
int tmp[50000];

void merge(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    int hl = l;
    int hr = mid + 1;
    int s = l - 1;
    while (hl <= mid && hr <= r)
    {
        if (x[hl] > x[hr])
        {
            ans += mid - hl + 1;
            s++;
            tmp[s] = x[hr];
            hr++;
        }
        else
        {
            s++;
            tmp[s] = x[hl];
            hl++;
        }
    }
    for (int i = hl; i <= mid; i++)
    {
        s++;
        tmp[s] = x[i];
    }
    for (int i = hr; i <= r; i++)
    {
        s++;
        tmp[s] = x[i];
    }
    for (int i = l; i <= r; i++)
    {
        x[i] = tmp[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    ans = 0;
    merge(1, n);
    printf("%d\n", ans);
    return 0;
}
