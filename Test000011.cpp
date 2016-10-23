#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long x[2000000];
long long que[2000000];
long long l[2000000];
long long r[2000000];
long long T[2000000];

int main()
{
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		//printf("%d ", x[i]);
		l[i] = 1;
		r[i] = n;
	}
	//printf("\n");
	int tail;
	tail = 0;
	for (int i = 1; i <= n; i++)
	{
	//	printf("x[%d] = %d\n", i, x[i]);
		while (tail && x[que[tail]] < x[i])
		{
			r[que[tail]] = i - 1;
			tail--;
		}
		tail++;
		que[tail] = i;
	}
	tail = 0;
	for (int i = n; i >= 1; i--)
	{
		//cout << i << ' ' << tail << ' ' << x[que[head]] << ' ' << x[i] << 	endl;
		while (tail && x[que[tail]] < x[i])
		{
			l[que[tail]] = i + 1;
			//cout << 'L' << que[head] << " " << l[que[head]] << endl;
			tail--;
		}
		tail++;
		que[tail] = i;
	}
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i << ' ' << l[i] << ' ' << r[i] << endl;
	//}
	for (int i = 1; i <= n; i++)
	{
		T[x[i]] = (i - l[i] + 1) * (r[i] - i + 1);
	}
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += T[i];
		if (s >= k)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
