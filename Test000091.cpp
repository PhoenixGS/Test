#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int _;
int x[10];
int total;
int last;
int T_T[100000];
int f[100000];

void add(int X)
{
	for (int i = total; i >= X; i--)
	{
		f[i] = f[i] | f[i - X];
	}
}

int main()
{
	_ = 0;
	total = 0;
	for (int i = 1; i <= 6; i++)
	{
		scanf("%d", &x[i]);
		total += x[i] * i;
	}
	while (total)
	{
		_++;
		if (total & 1)
		{
			printf("Collection #%d:\nCan't be divided.\n", _);
			total = 0;
			for (int i = 1; i <= 6; i++)
			{
				scanf("%d", &x[i]);
				total += x[i] * i;
			}
			if (total)
			{
				printf("\n");
			}
			continue;
		}
		memset(f, 0, sizeof(f));
		total /= 2;
		f[0] = 1;
		for (int i = 1; i <= 6; i++)
		{
			for (int j = 1; j <= x[i]; j *= 2)
			{
				add(j * i);
				x[i] -= j;
			}
			if (x[i])
			{
				add(x[i] * i);
			}
		}
		if (f[total])
		{
			printf("Collection #%d:\nCan be divided.\n", _);
		}
		else
		{
			printf("Collection #%d:\nCan't be divided.\n", _);
		}
		total = 0;
		for (int i = 1; i <= 6; i++)
		{
			scanf("%d", &x[i]);
			total += x[i] * i;
		}
		if (total)
		{
			printf("\n");
		}
	}
	return 0;
}
