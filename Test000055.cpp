void dfs(int u)
{
	for (int i = 1; (1 << i) <= dep[u]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = next[i])
		if (v[i] != fa[u][0])
		{
			fa[v[i]][0] = u;
			dep[v[i]] = dep[u] + 1;
			dfs(v[i]);
		}
}

int lca(int x,int y)
{
	if (dep[x] < dep[y])
	{
		swap(x,y);
	}
	for (int i = 17; i >= 0; i--)
	{
		if (dep[x] - (1 << i) >= dep[y])
		{
			x = fa[x][i];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int i = 17; i >= 0; i--)
	{
		if ((1 << i) <= dep[x] && fa[x][i] != fa[y][i])
		{	
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	depth[1] = 0;
	dfs(1);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		
	}
}
