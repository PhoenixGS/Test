#include <cstdio>

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		s[i] = s[i - 1] + x[i];
	}
	
}
