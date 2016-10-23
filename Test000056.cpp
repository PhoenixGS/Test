#include <cstdio>
#include <queue>

using namespace std;

int head[100005];
int next[1000005];
int vet[10000005];
int val[10000005];
int dis[100005];
int que[100005];
int inq[100005];
int inn[100005];
int edgenum;
int n, m;

void add(int u, int v, int cost)
{
	edgenum++;
	vet[edgenum] = v;
	val[edgenum] = cost;
	next[edgenum] = head[u];
	head[u] = edgenum;
}

bool Bellman_ford(int s)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 1000000000;
	}
	dis[s] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = true;
		for (int u = 1; u <= n; u++)
		{
			for (int e = head[u]; e; e = next[e])
			{
				int v = vet[e];
				int cost = val[e];
				if (dis[u] + cost < dis[v])
				{
					dis[v] = dis[u] + cost;
					flag = false;
				}
			}
		}
		if (flag)
		{
			return true;//没有负权圈
		}
	}
	for (int u = 1; u <= n; u++)
	{
		for (int e = head[u]; e; e = next[e])
		{
			int v = vet[e];
			int cost = val[e];
			if (dis[u] + cost < dis[v])
			{
				return false;//有负权圈
			}
		}
	}
	return true;//没有负权圈
}

bool SPFA(int s)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 1000000000;
		inq[i] = false;
		inn[i] = 0;
	}
	dis[s] = 0;
	int h = 0;
	int t = 0;
	que[0] = s;
	inq[s] = true;
	inn[s] = 1;
	while (h <= t)
	{
		int u = que[h % n];
		inq[u] = false;
		for (int e = head[u]; e; e = next[e])
		{
			int v = vet[e];
			int cost = val[e];
			if (dis[u] + cost < dis[v])
			{
				dis[v] = dis[u] + cost;
				if (! inq[v])
				{
					t++;
					que[t % n] = v;
					inq[v] = true;
					inn[v]++;
					if (inn[v] == n)
					{
						return false;
					}
				}
			}
		}
		h++;
	}
	return true;
}

bool SPFA_STL(int s)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 1000000000;
		inq[i] = false;
		inn[i] = 0;
	}
	dis[s] = 0;
	int h = 0;
	int t = 0;
	que[0] = s;
	inq[s] = true;
	inn[s] = 1;
	while (h <= t)
	{
		int u = que[h % n];
		inq[u] = false;
		for (int e = head[u]; e; e = next[e])
		{
			int v = vet[e];
			int cost = val[e];
			if (dis[u] + cost < dis[v])
			{
				dis[v] = dis[u] + cost;
				if (! inq[v])
				{
					t++;
					que[t % n] = v;
					inq[v] = true;
					inn[v]++;
					if (inn[v] == n)
					{
						return false;
					}
				}
			}
		}
		h++;
	}
	return true;
}

int main()
{
	edgenum = 0;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	Bellman_ford(1);
	//SPFA(1);
	printf("%d\n", dis[n]);
	return 0;
}
