#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int x[200000];
int tmpA[200000];
int tmpB[200000];
int lastA;
int lastB;
int n;
int ans = 0;

void dfs(int k, int s)
{
	if (k == n)
	{
		ans = max(ans, s);
		/*for (int i = 1; i <= lastA; i++)
		{
			printf("%d ", tmpA[i]);
		}
		printf("    ");
		for (int i = 1; i <= lastB; i++)
		{
			printf("%d ", tmpB[i]);
		}
		printf("\n");*/
		return;
	}
	lastA++;
	tmpA[lastA] = x[k];
	if (lastA == 1)
	{
		dfs(k + 1, s + 1);
	}
	if (lastA == 2)
	{
		if (tmpA[lastA - 1] == tmpA[lastA])
		{
			dfs(k + 1, s + 1);
		}
		else
		{
			dfs(k + 1, s + 2);
		}
	}
	if (lastA > 2)
	{
		int t = 0;
		if (tmpA[lastA - 2] != tmpA[lastA - 1])
		{
			t++;
		}
		if (tmpA[lastA - 1] != tmpA[lastA])
		{
			t++;
		}
		if (tmpA[lastA - 2] != tmpA[lastA])
		{
			t++;
		}
		if (t == 0)
		{
			dfs(k + 1, s + 1);
		}
		if (t == 2)
		{
			dfs(k + 1, s + 2);
		}
		if (t == 3)
		{
			dfs(k + 1, s + 3);
		}
	}
	lastA--;
	lastB++;
	tmpB[lastB] = x[k];
	if (lastB == 1)
	{
		dfs(k + 1, s + 1);
	}
	if (lastB == 2)
	{
		if (tmpB[lastB - 1] != tmpB[lastB])
		{
			dfs(k + 1, s + 2);
		}
		else
		{
			dfs(k + 1, s + 1);
		}
	}
	if (lastB > 2)
	{
		int t = 0;
		if (tmpB[lastB - 2] != tmpB[lastB - 1])
		{
			t++;
		}
		if (tmpB[lastB - 1] != tmpB[lastB])
		{
			t++;
		}
		if (tmpB[lastB - 2] != tmpB[lastB])
		{
			t++;
		}
		if (t == 0)
		{
			dfs(k + 1, s + 1);
		}
		if (t == 2)
		{
			dfs(k + 1, s + 2);
		}
		if (t == 3)
		{
			dfs(k + 1, s + 3);
		}
	}
	lastB--;
}

int main()
{
	scanf("%d", &n);
	string st;
	cin >> st;
	for (int i = 0; i < st.length(); i++)
	{
		if (st[i] == 'M')
		{
			x[i] = 0;
		}
		if (st[i] == 'B')
		{
			x[i] = 1;
		}
		if (st[i] == 'F')
		{
			x[i] = 2;
		}
	}
	ans = 0;
	lastA = 0;
	lastB = 0;
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
