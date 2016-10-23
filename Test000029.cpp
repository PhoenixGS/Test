#include <cstdio>
#include <iostream>

using namespace std;

int n, l;
int x[60000];
long long s[60000];
long long f[60000];
long long que[60000];

long long g(int i)
{
	return s[i] + i;
}

long long h(int i)
{
	return s[i] + i + l + 1;
}

long long up(int j, int k)
{
	return f[j] - f[k] + h(j) * h(j) - h(k) * h(k);
}

long long down(int j, int k)
{
	return 2 * (h(j) - h(k));
}

long long calc(int i, int j)
{
	return f[j] + (g(i) - h(j)) * (g(i) - h(j));
}

int main()
{
	scanf("%d%d", &n, &l);
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
		while (tail - head >= 1 && calc(i, que[head]) > calc(i, que[head + 1]))
		{
			head++;
		}
		f[i] = f[que[head]] + (g(i) - h(que[head])) * (g(i) - h(que[head]));
		while (tail - head >= 1 && up(que[tail - 1], que[tail]) * down(que[tail], i) > up(que[tail], i) * down(que[tail - 1], que[tail]))
		{
			tail--;
		}
		tail++;
		que[tail] = i;
	}
	cout << f[n] << endl;
	return 0;
}
