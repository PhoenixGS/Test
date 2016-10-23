#include <cstdio>
#include <algorithm>

using namespace std;

int x[100];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int x;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
		}
		printf("%d\n", abs(x));
	}
	return 0;
}
