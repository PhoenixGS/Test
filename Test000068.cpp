#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

int edgenum;
int que[200005];
int vet[400000];
int val[400000];
int next[400000];
int head[200000];
long long dis[200000];
bool inq[200000];
int inn[200000];
int n, k;

void add(int u, int v, int cost)
{
	edgenum++;
	vet[edgenum] = v;
	val[edgenum] = cost;
	next[edgenum] = head[u];
	head[u] = edgenum;
}

bool SPFA(int s)
{
	int headX = 0;
	int tailX = 0;
	que[0] = 0;
	dis[s] = 0;
	inq[s] = true;
	inn[s] = 1;
	while (headX <= tailX)
	{
		int u = que[headX % 200000];
		headX++;
		inq[u] = false;
		for (int e = head[u]; e; e = next[e])
		{
			int v = vet[e];
			int cost = val[e];
			if (dis[u] + cost > dis[v])
			{
				dis[v] = dis[u] + cost;
				if (! inq[v])
				{
					tailX++;
					que[tailX % 200000] = v;
					inq[v] = true;
					inn[v]++;
					if (inn[v] == n)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	edgenum = 0;
	scanf("%d%d", &n, &k);
	for (int i = n; i >= 1; i--)
	{
		add(0, i, 1);
	}
	for (int i = 1; i <= k; i++)
	{
		int x, a, b;
		scanf("%d%d%d", &x, &a, &b);
		if (x == 1)
		{
			add(a, b, 0);
			add(b, a, 0);
		}
		if (x == 2)
		{
			add(a, b, 1);
		}
		if (x == 3)
		{
			add(b, a, 0);
		}
		if (x == 4)
		{
			add(b, a, 1);
		}
		if (x == 5)
		{
			add(a, b, 0);
		}
	}
	if (SPFA(0) == false)
	{
		printf("-1\n");
		return 0;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += dis[i];
	}
	cout << ans << endl;
	return 0;
}
