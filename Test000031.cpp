#include <cstdio>
#include <iostream>

using namespace std;

int n;
int a, b, c;
int x[2000000];
long long s[2000000];
long long f[2000000];
long long que[2000000];

long long g(int i)
{
	return f[i] + a * s[i] * s[i] - b * s[i];
}

long long up(int k, int j)
{
	return g(k) - g(j);
}

long long down(int k, int j)
{
	return 2 * a * (s[k] - s[j]);
}

long long calc(int i, int j)
{
	return f[j] + a * (s[i] - s[j]) * (s[i] - s[j]) + b * (s[i] - s[j]) + c;
}

int main()
{
	scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		s[i] = s[i - 1] + x[i];
	}
	int head = 0;
	int tail = 0;
	que[head] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (tail - head >= 1 && calc(i, que[head]) <= calc(i, que[head + 1]))
		{
			head++;
		}
		f[i] = calc(i, que[head]);
		while (tail - head >= 1 && up(que[tail - 1], que[tail]) * down(que[tail], i) >= up(que[tail], i) * down(que[tail - 1], que[tail]))
		{
			tail--;
		}
		tail++;
		que[tail] = i;
	}
	cout << f[n] << endl;
	return 0;
}
