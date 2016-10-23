#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int c[300];
int u[300];
int Out[300];
int In[300];
vector<int> vet[300];
vector<int> val[300];
deque<int> que;

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &c[i], &u[i]);
	}
	for (int i = 1; i <= p; i++)
	{
		int X, Y, cost;
		scanf("%d%d%d", &X, &Y, &cost);
		vet[X].push_back(Y);
		val[X].push_back(cost);
		Out[X]++;
		In[Y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (In[i] == 0 && c[i] > 0)
		{
			que.push_back(i);
		}
		else
		{
			c[i] -= u[i];
		}
	}
	while (! que.empty())
	{
		int u = que.front();
		que.pop_front();
		for (int j = 0; j < vet[u].size(); j++)
		{
			int v = vet[u][j];
			c[v] += val[u][j] * c[u];
			In[v]--;
			if (In[v] == 0 && c[v] > 0)
			{
				que.push_back(v);
			}
		}
	}
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Out[i] == 0 && c[i] > 0)
		{
			total++;
			printf("%d %d\n", i, c[i]);
		}
	}
	if (total == 0)
	{
		printf("NULL\n");
	}
	return 0;
}
