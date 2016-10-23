#include <cstdio>

int x[300000];
int flag[300000];
int time[300000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	int ans = 300000;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == false)
		{
			int now = 1;
			flag[i] = i;
			time[i] = 1;
			int tmp = i;
			while (true)
			{
				tmp = x[tmp];
				if (flag[tmp] != 0)
				{
					break;
				}
				now++;
				time[tmp] = now;
				flag[tmp] = i;
			}
			if (flag[tmp] == i && now + 1 - time[tmp] < ans)
			{
				ans = now + 1 - time[tmp];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
