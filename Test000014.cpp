#include <cstdio>
#include <iostream>

using namespace std;

long long x[60000];
long long y[60000];
long long xx[60000];
long long yy[60000];
long long f[60000];
long long que[60000];

int min(long long x, long long y)
{
	if (x > y)
	{
		return y;
	}
	return x;
}

void qsort(int l, int r)
{
	long long midx = x[(l + r) / 2];
	long long midy = y[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (x[i] < midx || x[i] == midx && y[i] > midy)
		{
			i++;
		}
		while (x[j] > midx || x[j] == midx && y[j] < midy)
		{
			j--;
		}
		if (i <= j)
		{
			long long t;
			t = x[i];
			x[i] = x[j];
			x[j] = t;
			t = y[i];
			y[i] = y[j];
			y[j] = t;
			i++;
			j--;
		}
	}
	if (l < j)
	{
		qsort(l, j);
	}
	if (i < r)
	{
		qsort(i, r);
	}
}

long long up(int j, int k)
{
    return f[j] - f[k];
}

long long down(int j, int k)
{
    return yy[k + 1] - yy[j + 1];
}

long long calc(int i, int j)
{
    //printf("X%d %d %d\n", xx[i], yy[j + 1], j + 1);
    cout << f[i] << " " << xx[i] << " " << j + 1 << endl;
    
    return f[i] + xx[i] * yy[j + 1];
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &x[i], &y[i]);
	}
	qsort(1, n);
	int num = 0;
    for (int i = 1; i <= n; i++)
    {
        while (num > 0 && yy[i] > yy[num])
            num--;
        num++;
        xx[num] = x[i];
        yy[num] = y[i];
    }

	for (int i = 1; i <= num; i++)
	{
		f[i] = 5000000000000;
	}
    int head = 0;
    int tail = -1;
    for (int i = 1; i <= num; i++)
    {
        while (head < tail && calc(i, que[head + 1]) <= calc(i, que[head]))
        {
            head++;
        }
        cout << i << endl;
        f[i] = calc(i, que[head]);
        while (head < tail && up(que[tail], que[tail - 1]) * down(i, que[tail]) >= up(i, que[tail]) * down(que[tail], que[tail - 1]))
        {
            tail--;
            que[tail] = tail + 1;
        }
        tail++;
        que[tail] = i;
        //for (int j = head; j <= tail; j++)
        //{
        //    printf("%d ", que[j]);
        //}
        //printf("\n");
        //cout << "x" << f[i] << endl;
    }
    cout << f[num] << endl;
	return 0;
}
