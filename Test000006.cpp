#include <cstdio>
#include <algorithm>

using namespace std;

int x[40000];
int F1[40000][4];
int F2[40000][4];

int calc(int x, int y)
{
	if (x == y)
	{
		return 0;
	}
	return 1;
}	

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		F1[i][1] = F1[i - 1][1] + calc(1, x[i]);
		F1[i][2] = min(F1[i - 1][1], F1[i - 1][2]) + calc(2, x[i]);
		F1[i][3] = min(min(F1[i - 1][1], F1[i - 1][2]), F1[i - 1][3]) + calc(3, x[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		F2[i][3] = F2[i - 1][3] + calc(3, x[i]);
		F2[i][2] = min(F2[i - 1][3], F2[i - 1][2]) + calc(2, x[i]);
		F2[i][1] = min(min(F2[i - 1][3], F2[i - 1][2]), F2[i - 1][1]) + calc(1, x[i]);
	}
	int ans = 1000000000;
	for (int i = 1; i <= 3; i++)
	{
		ans = min(ans, min(F1[n][i], F2[n][i]));
		//printf("%d %d\n", F1[n][i], F2[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
