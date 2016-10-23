#include <cstdio>
#include <iostream>

using namespace std;

int n;
int a, b, c;
long long f[2000000];
int x[2000000];
long long s[2000000];
int que[2000000];

long long calc(int i, int j)
{
	return f[j] + a * (s[i] - s[j]) * (s[i] - s[j]) + b * (s[i] - s[j]) + c;
}

long long g(int i)
{
	return f[i] - b * s[i] + a * s[i] * s[i];
}

long long up(int j, int k)
{
	return g(j) - g(k);
}

long long down(int j, int k)
{
	return 2 * a * (s[j] - s[k]);
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
	que[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (head + 1 <= tail && calc(i, que[head]) <= calc(i, que[head + 1]))
		{
			head++;
		}
		f[i] = calc(i, que[head]);
		while (head + 1 <= tail && up(que[tail - 1], que[tail]) * down(que[tail], i) >= up(que[tail], i) * down(que[tail - 1], que[tail]))
		{
			tail--;
		}
		tail++;
		que[tail] = i;
	}
	cout << f[n] << endl;
	return 0;
}
